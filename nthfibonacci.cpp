
// CPP program to find n-th Fibonacci number 
#include <bits/stdc++.h> 
using namespace std; 
  
// Approximate value of golden ratio 
double PHI = 1.6180339; 
  
// Fibonacci numbers upto n = 5 
int f[6] = { 0, 1, 1, 2, 3, 5 }; 
  
// Function to find nth 
// Fibonacci number 
int fib (int n) 
{ 
    // Fibonacci numbers for n < 6 
    if (n < 6) 
        return f[n]; 
  
    // Else start counting from  
    // 5th term 
    int t = 5, fn = 5; 
  
    while (t < n) { 
         fn = round(fn * PHI); 
         t++; 
    } 
  
    return fn;    
} 
  
// driver code 
int main() 
{ 
    int n = 9; 
  
    cout << n << "th Fibonacci Number = " 
         << fib(n) << endl; 
  
    return 0; 
} 
