<?php

//var_dump($argv);

if(in_array("--help", $argv, TRUE)){
    echo "
        ____                  __
       / __ \                / /
      / /_/ /__  ____  _____/ /_  __  __
     / __  / _ \/ __ \/ ___/ __ \/ / / /
    / /_/ /  __/ / / / /__/ / / / /_/ /
    \____/\___/_/ /_/\___/_/ /_/\__, /
                               /____/  ";
    echo "\n";
    echo "Welcome to Benchy v0.1! \n";
    echo "\n";
    echo "By default, benchy will try to use make file inside of the scheme folder \n";
    echo "	and will try to execute scheme.exe inside of the scheme folder. \n";
    echo "	Otherwise, you can specify these files as shown below: \n";
    echo "\n";
    echo "Usage: benchy [absolute/path/to/project/folder] [name-of-executable-file] [options] \n";
    echo "Example usage: benchy /home/user/scheme scheme.exe -v \n \n";
    echo "       -v	verbose \n";
    echo "       -nodb	don't submit results to the database \n";
    echo "       -d	debugging mode for bechmarking files manually, without connecting to the database \n";
    echo "       -r	development mode (retry compiling and/or executing after 3 seconds if an error occures.";
    echo "                  It is useful for developing and not having to run benchy over and over again.) \n";

    echo "\n \n";
    die();
}

$currentDirectory = getcwd().'/';

// Check for given file paths
// Get the first character of the first given argument
if(mb_substr($argv[1], 0, 1, "UTF-8") != "-"){
  // So this is a file path, not option

  // Get the second character of the first given argument
  if(mb_substr($argv[1], 0, 1, "UTF-8") == "/"){
    // Get the path if it is absolute
    $projectFolderPath = $argv[1];

  } else {
    echo ("Please enter an absolute path for project folder \n \n");
    die();
  }

}

// Check for given file paths
// Get the first character of the second given argument
if(mb_substr($argv[2], 0, 1, "UTF-8") != "-"){
  // So this is a file path, not option

  // Get the second character of the second given argument
  if(mb_substr($argv[2], 0, 1, "UTF-8") != "/"){
    // Get the path if it is absolute
    $executableFile = $argv[2];

  } else {
    echo ("Please the name of the executable file, not a path \n");
    echo ("For example -> benchy /path/to/project/folder scheme.exe \n \n");
    die();
  }

}


if(in_array("-v", $argv, TRUE)){
    $verbose = TRUE;
    echo "# Verbose mode enabled # \n";

} else {
    $verbose = FALSE;

}

if(in_array("-nodb", $argv, TRUE)){
    $nodb = TRUE;
    echo "# Database submission disabled # \n";

} else {
    $nodb = FALSE;

}

if(in_array("-d", $argv, TRUE)){
    $debug = TRUE;
    $nodb = TRUE;
    echo "# Debugging mode enabled # \n";

} else {
    $debug = FALSE;

}

if(in_array("-r", $argv, TRUE)){
    $development = TRUE;
    echo "# Development mode enabled # \n";

} else {
    $development = FALSE;

}

$error = FALSE;

echo "\n";

// https://symfony.com/doc/current/components/process.html
// https://github.com/cocur/background-process
// composer require symfony/process

// Include Symfony Process
require_once 'vendor/autoload.php';
use Symfony\Component\Process\Exception\ProcessFailedException;
use Symfony\Component\Process\Process;


/////////////////////////////////////////////
// Get list of unprocessed schemes from DB //
/////////////////////////////////////////////
// Database details
$servername = "204.152.211.39";
$username = "bsimsekc_obw";
$password = "e3obw123**";
$database = "bsimsekc_obw";

while(TRUE){
    // Connect to database if debugging is not enabled
    if(!$debug){
    	// Create connection
    	if($verbose){ echo "-- Connecting to database -- \n";}
    	$conn = mysqli_connect($servername, $username, $password, $database);

    	// Check connection
    	if (!$conn) {
    	    die("Connection failed: " . mysqli_connect_error());
    	}

    	$sql = "SELECT DISTINCT schemes.id, schemes.title, schemes.attached_files, queue.processed
    		FROM schemes
    		INNER JOIN queue on schemes.id = queue.scheme_id
    		WHERE queue.processed = '0'
    		ORDER BY queue.updated_at ASC";

    	if($verbose){ echo "-- Retrieving queue from the database -- \n";}
    	$result = $conn->query($sql);

    	if (mysqli_num_rows($result) > 0) {
    	  $row = $result->fetch_assoc();
    	  $nothingToProcess = False;
    	  if($verbose){ echo "-- Found unproccessed schemes in the queue -- \n";}

    	} else {
    	  if($verbose){ echo "-- There are no unproccessed schemes in the queue -- \n";}
    	  $nothingToProcess = True;

    	}

    	$conn->close();
    	  if($verbose){ echo "-- Closed database connection -- \n";}

    	//echo "<pre>";
    	//print_r($row);

    } else {
    	$nothingToProcess = FALSE;
    }

    //////////////////////////
    // Do the benchmarkings //
    //////////////////////////
    // Don't process anything if there is nothing in the queue
    if((!$nothingToProcess)||($debug)){

        while(TRUE){

            // Compile first
            if($verbose){ echo "-- Compiling scheme -- \n";}
            $compile = new Process('cd '.$projectFolderPath.' && make');
            $compile->setTimeout(6000); // in seconds
            $compile->run();

            // executes after the command finishes
            if (!$compile->isSuccessful()) {
                $error = TRUE;
                // Show compilation errors
                //throw new ProcessFailedException($compile);
                if($verbose){
                  echo "#######################\n";
                  echo "## COMPILATION ERROR ##\n";
                  echo "#######################\n";
                  echo (new ProcessFailedException($compile));
                  echo "\n";
                }

                if($development){
                  echo "###########################\n";
                  echo "## RETRYING IN 3 SECONDS ##\n";
                  echo "###########################\n";
                  echo "\n";
                  sleep(3);
                }

            } else {
                $error = FALSE;
                if($verbose){ echo "-- Compiled successfully -- \n \n";}

          	    // Now run the code if there are no errors
          	    if($verbose){ echo "-- Executing scheme (might take a while) -- \n";}
          	    $process = new Process('cd '.$projectFolderPath.' && ./'.$executableFile);
                $process->setTimeout(6000); // in seconds
          	    $process->run();

          	    // executes after the command finishes
          	    if (!$process->isSuccessful()) {
                    $error = TRUE;
          		      //throw new ProcessFailedException($process);
                    if($verbose){
                      echo "###################\n";
                      echo "## RUNTIME ERROR ##\n";
                      echo "###################\n";
                      echo (new ProcessFailedException($process));
                      echo "\n";
                    }

                    if($development){
                      echo "###########################\n";
                      echo "## RETRYING IN 3 SECONDS ##\n";
                      echo "###########################\n";
                      echo "\n";
                      sleep(3);
                    }

          	    } else {
                    $error = FALSE;
                    if($verbose){ echo "-- Executed successfully -- \n \n";}

                    $output = $process->getOutput();

                    if($verbose){ echo "--> Here is the output \n".$output."\n";}
                    if($verbose){ echo "--> Here is the decoded output \n";}
                    if($verbose){ var_dump(json_decode($output, true));}

                    $benchmark_results = json_decode($output, true);

                    echo "\n";
          	    }

            }

            // Break out of the while loop if there are no errors
            if((!$development)||(!$error)){break;}
        }

        /////////////////////////////////
        // Send results back to the DB //
        /////////////////////////////////
        // Don't try messing with DB unless -nodb enabled or debugging is not enabled
        if((!$nodb)||(!$debug)){
          // Create connection
            $conn = mysqli_connect($servername, $username, $password, $database);

            // Check connection
            if (!$conn) {
                die("Connection failed: " . mysqli_connect_error());
            }

            // Update benchmark values
            $sql = "UPDATE schemes SET speed = $output WHERE id = "."'".$row['id']."'";
            $conn->query($sql);

            // Mark this scheme as processed in the queue
            $sql = "UPDATE queue SET processed = '1' WHERE scheme_id = "."'".$row['id']."'";
            $conn->query($sql);

            $conn->close();

            echo "processed ".$row['id'].", aka".$row['title']."\n";

          }

    } else {
      echo "-- Nothing is processed or submitted to the database -- \n";
    }

    if(!$development){
      break;

    } else {
      echo "#########################################\n";
      echo "##            YIKES, WORKS!            ##\n";
      echo "#########################################\n";
      echo "##      RUNNING AGAIN IN 3 SECONDS     ##\n";
      echo "#########################################\n";
      echo "## USE CTRL+C TO EXIT DEVELOPMENT MODE ##\n";
      echo "#########################################\n";
      echo "\n \n";
      sleep(3);

    }
}
?>
