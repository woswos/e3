<?php

// var_dump($argv);

if(in_array("--help", $argv, TRUE)){
    echo "Welcome to benchy v0.1! \n";
    echo "\n";
    echo "By default, benchy will try to use make file inside of the scheme folder \n";
    echo "	and will try to execute scheme.exe inside of the scheme folder. \n";
    echo "	Otherwise, you can specify these files as shown below: \n"; 
    echo "\n";
    echo "Usage: benchy [options] [absolute/path/to/make-file] [absolute/path/to/executable-file] \n";
    echo "       -v	verbose \n";
    echo "       -nodb	don't submit results to the database";
    echo "       -d	debugging mode for bechmarking files manually, without connecting to the database";

    echo "\n \n";
    die();
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

echo "\n";

/////////////////////////////////////////////
// Get list of unprocessed schemes from DB //
/////////////////////////////////////////////
// Database details
$servername = "204.152.211.39";
$username = "bsimsekc_obw";
$password = "e3obw123**";
$database = "bsimsekc_obw";

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
// https://symfony.com/doc/current/components/process.html
// https://github.com/cocur/background-process
// composer require symfony/process

// Include Symfony Process
require_once 'vendor/autoload.php';
use Symfony\Component\Process\Exception\ProcessFailedException;
use Symfony\Component\Process\Process;

// Don't process anything if there is nothing in the queue
if((!$nothingToProcess)||($debug)){

    // Compile first
    if($verbose){ echo "-- Compiling scheme -- \n";}
    $compile = new Process('cd scheme && make');
    $compile->run();

    // executes after the command finishes
    if (!$compile->isSuccessful()) {
        // Show compilation errors
        throw new ProcessFailedException($compile);
    } else {
        if($verbose){ echo "-- Compiled successfully -- \n \n";}


	    // Now run the code if there are no errors
	    if($verbose){ echo "-- Executing scheme -- \n";}
	    $process = new Process('cd scheme && ./scheme.exe');
	    $process->run();

	    // executes after the command finishes
	    if (!$process->isSuccessful()) {
		throw new ProcessFailedException($process);
	    } else {
	    	if($verbose){ echo "-- Executed successfully -- \n \n";}
	    }

	    $output = $process->getOutput();

	    echo "--> Here is the output: \n";
	    echo $output;
 
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

?>
