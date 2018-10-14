<?php
function Palindrome($number){ 
	return (strrev($number) === $number) ? 'true' : 'false';
} 
 
$string = '1234321'; 
echo Palindrome($string);

?>