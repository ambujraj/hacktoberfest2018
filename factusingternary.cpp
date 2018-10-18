#include<iostream> 
  
int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 
  
// Driver Code 
int main() 
{ 
    int num = 5; 
    printf ("Factorial of %d is %d", num, factorial(num)); 
    return 0; 
} 
