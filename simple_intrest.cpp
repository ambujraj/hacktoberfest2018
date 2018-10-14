#include<iostream>
using namespace std;

int main()
{
	int p,r,t,i;
	cout<<"Enter Principle : "<<"\n";
	cin>>p;
	cout<<"Enter Rate : "<<"\n";
	cin>>r;
	cout<<"Enter Time : "<<"\n";
	cin>>t;
	i=(p*r*t)/100;
	cout<<"Simple interest is : "<<i;

	
	return 0;
}
/* Example
Input-
Enter Principle : 1000
Enter Rate :5
Enter Time :2
Output-
Simple interest is :100
*/
