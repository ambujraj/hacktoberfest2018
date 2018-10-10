/* 
    Write a program that prints the numbers from 1 to 100. 
    But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. 
    For numbers which are multiples of both three and five print “FizzBuzz”.
*/

[...Array(100)].map((_,i) =>
 console.log(!(++i%15)?'Fizzbuz':!(i%3) ? 'Fizz':!(i%5)?'Buzz':i));