#include<iostream>
using namespace std;

long long int factorial(int n)
{
	if(n==0)	
        return 1;
	
	return n*factorial(n-1);
}

int main()
{
	int n;
	cout<<"Enter Number whose factorial is to be calculated : ";
	cin>>n;
	cout<<"The factorial of "<<n<<" is "<<factorial(n)<<endl;
	return 0;
}
