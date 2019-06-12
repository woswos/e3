<?php

$debug = True;

/////////////////////////////////////////////
// Get list of unprocessed schemes from DB //
/////////////////////////////////////////////
// Database details
$servername = "204.152.211.39";
$username = "bsimsekc_obw";
$password = "e3obw123**";
$database = "bsimsekc_obw";

// Create connection
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
$result = $conn->query($sql);

if (mysqli_num_rows($result) > 0) {
  $row = $result->fetch_assoc();
  $nothingToProcess = False;
} else {
  $nothingToProcess = True;
}

$conn->close();

//echo "<pre>";
//print_r($row);


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

// Run commands is there is something to process or debugging is enabled
if((!$nothingToProcess)||($debug)){

    // Compile first
    echo "Compiling \n";
    $compile = new Process('g++ -std=c++14 -Itfhe_unx/inc/tfhe api.cpp tfhe_unx/libtfhe.a tfhe_unx/libfftw3.a -o api.exe');
    $compile->run();

    // executes after the command finishes
    if (!$compile->isSuccessful()) {
        // Show compilation errors
        throw new ProcessFailedException($compile);
    } else {
    	echo "Compiled successfully \n \n";
    }


    // No run the code
    echo "Executing \n";
    $process = new Process('./api.exe');
    $process->run();

    // executes after the command finishes
    if (!$process->isSuccessful()) {
        throw new ProcessFailedException($process);
    } else {
    	echo "Executed successfully \n \n";
    }

    $output = $process->getOutput();

    echo "Here is the output: \n";
    echo $output;
  
 
    /////////////////////////////////
    // Send results back to the DB //
    /////////////////////////////////
    // Don't try messing with DB unless there was a reall process
    if(!$nothingToProcess){
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
  echo "nothing is processed \n";
}

?>
