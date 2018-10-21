//0-1 Knapsack problem using dynamic programming 
#include<iostream.h> 
  
int max(int a, int b) { return (a > b)? a : b; } 
   
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
void main() 
{ 
    int val[] = {50, 110, 115}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = 1; 
    int c=knapSack(W, wt, val, n); 
    cout<<c; 
} 
