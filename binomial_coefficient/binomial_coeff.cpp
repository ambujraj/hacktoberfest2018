
//Calculating binomial coefficient using recursion
#include<iostream.h> 
   
int binomialCoeff(int n, int k) 
{   if (k==0 || k==n) 
      return 1; 
 
    return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k); 
} 
  
void main() 
{ 
    int n,c,k; 
    cout<< "enter value of n:";
    cin>>n;
    cout<< "enter value of k:";
    cin>>k;
    c= binomialCoeff(n,k);
    cout<<n<< "C"<< k<< " is: "<<c;
    
} 
