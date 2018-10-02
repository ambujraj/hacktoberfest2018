//factorial using recursion
#include<iostream>
using namespace std;
int fact(int n)
	if(n==0)
		return 1;
  return n*fact(n-1);
}
int main()
{
	int n;
	cin>>n;
	cout<<"Factorial of the entered no. is :<< fact(n);
}
	
