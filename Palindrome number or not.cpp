#include<iostream>
using namespace std;

int main ()
{
	cout<<" check whether the number is a palindrome or not "<<endl;
	int n,rev=0;
	cin>>n;
	int t=n;
	for( ; n>0; )
	{
		rev= 10*rev +n%10;
		n=n/10;
	}
	if(rev==t)
	cout<<" the number is a palindrome"<<endl;
	else cout<<" the number is not a palindrome"<<endl;
	return 0;
	
}
