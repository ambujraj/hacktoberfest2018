//Fibonacci Series using Iterative Method
#include <iostream>

using namespace std;

void fibonacci(int n)
{
	
	int f1 = 0;
	int f2 = 1;
	int f3 = 0;
	
	if(n==1)
		cout<<f1;
	else if(n==2)
		cout<<f1<<" "<<f2;
	else
	{
		cout<<f1<<" "<<f2<<" ";
		for(int i = 3;i<=n;i++)
		{
			f3=f1+f2;
			cout<<f3<<" ";
			f1=f2;
			f2=f3;
		}
		
	}
	cout<<"\n";	
}


int main()
{
	int n;
	cout<<"Enter the terms upto which the Fibonnaci Series has to be printed\n";
	cin>>n;
	fibonacci(n);
	
	return 0;
}
