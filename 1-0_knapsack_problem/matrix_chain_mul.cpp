
//chain matrix multiplication using recursion
#include<iostream.h> 
 
int Order(int m[], int i, int j) 
{ 
    if(i == j) 
        return 0; 
    int k; 
    int min=0; 
    int count; 
  
    for (k = i; k <j; k++) 
    { 
        count = Order(m, i, k) + 
                Order(m, k+1, j) + 
                m[i-1]*m[k]*m[j]; 
  
        if (count < min) 
            min = count; 
    } 
  
    return min; 
} 
  

void main() 
{ 
    int arr[] = {1, 2, 3, 4, 5}; 
    int n = 5; 
  
    int c=Order(arr, 1, n-1)); 
    cout<< "min no. of multiplications is: "<< c;
 }
