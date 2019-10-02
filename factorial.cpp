//Basic Example for Direct Recursion.(Factorial of Number)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(int n)
{
    if (n < = 1) // base case
        return 1;
    else    
        return n*fact(n-1);    
}

int main()
{
      int n;
      cout<<"Enter the Number?\n";
      cin>>n;
      cout<<"Factorial of n is:"<<fact(n);
}
