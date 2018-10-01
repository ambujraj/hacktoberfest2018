#include <iostream>
using namespace std;
int main()
{
	int n,remainder,reverse=0,originalnumber;
	cin>>n;
	originalnumber=n;
	while(n!=0){
		remainder = n%10;
		reverse=reverse*10 +remainder;
		n/=10;
	}
	(originalnumber==reverse)?cout<<"palindrome":cout<<"not palindrome";
return 0;
}
