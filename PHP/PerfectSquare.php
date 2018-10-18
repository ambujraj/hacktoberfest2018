<?php

//Hacktoberfest 2018 (is number a perfect square)

if(!empty($argv['1'])) {
	echo isPerfectSquare($arg['1']);
} else {
	echo 'Please input a valid number. (Please follow this command: php Persquare.php <number>)';
}


function isPerfectSquare($input)
{
	$input = intval($input);
	return gmp_perfect_square($input);
}
