<?php

// https://symfony.com/doc/current/components/process.html
// https://github.com/cocur/background-process
// composer require symfony/process

// Include Symfony Process
require_once 'vendor/autoload.php';
use Symfony\Component\Process\Exception\ProcessFailedException;
use Symfony\Component\Process\Process;

	echo "-- Compiling -- \n";

	$cmake = new Process('cd benchy && make');
	$cmake->setTimeout(6000); // in seconds
    $cmake->run();

	// executes after the command finishes
	if (!$cmake->isSuccessful()) {
		throw new ProcessFailedException($cmake);
	die();

	} else {
		echo "-- Compiled successfully -- \n \n";
	}


	echo "-- Executing -- \n \n";

	$execute = new Process('cd benchy && ./main.exe');
	$execute->setTimeout(6000); // in seconds
	$execute->run();

	// executes after the command finishes
	if (!$execute->isSuccessful()) {
		throw new ProcessFailedException($execute);
	die();

	}

	$output = $execute->getOutput();

	echo "--> Here is the output \n";
	echo $output;

?>
