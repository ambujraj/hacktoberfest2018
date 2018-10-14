<?php 
function facto($num){ 
    $fact = 1; 
    for ($i = 1; $i <= $num; $i++){ 
      $fact = $fact * $i; 
    } 
    return $fact; 
} 
$number = 5; 
$fact = facto($number); 
echo "Factorial = $fact"; 
?> 
