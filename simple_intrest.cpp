#include<iostream>
using namespace std;

int main()
{
	int p,r,t,i;
	cout<<"Enter Principle : ";
	cin>>p;
	cout<<"Enter Rate : ";
	cin>>r;
	cout<<"Enter Time : ";
	cin>>t;
	i=(p*r*t)/100;
	cout<<"Simple interest is : "<<i;

	
	return 0;
}
