
<?php   
    //Recursive function
function Fibonacci($number){ 
      
    // if and else if to generate first two numbers 
    if ($number == 0) 
        return 0;     
    else if ($number == 1) 
        return 1;     
      
    // Recursive Call to get the upcoming numbers 
    else
        return (Fibonacci($number-1) +  
                Fibonacci($number-2)); 
} 
  
$number = 10; 
for ($counter = 0; $counter < $number; $counter++){   
    echo Fibonacci($counter),' '; 
} 