#include<iostream>

using namespace std;

long int fib(long int i)
{
	if(i==1)	return 1;
	if(i==0)	return 0;
	else	return fib(i-1) + fib(i-2);
}
int main()
{
	long int n;
	cout<<"Enter number of terms to be shown of the Fibonacci Series,starting from 1 : ";
	cin>>n;
	cout<<"The first n terms of the fibonacci series are :\n 1";
	for(long int i=2;i<=n;i++)
		cout<<" , "<<fib(i);
	cout<<endl;
	return 0;
}