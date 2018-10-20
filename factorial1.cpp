#include<iostream>
using namespace std;
int main() 
{
	int num,fact=1;
	cout<<" Enter the no: for which you want the factorial";
	cin>>num;
	for (int i=1;i<=num;i++)
     {
		fact=fact*i;
	}
	cout<<"Factorial of Given Number is ="<<fact<<endl;
	return 0;
}