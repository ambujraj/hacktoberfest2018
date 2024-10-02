// in this we can find the whether no is prime or not up to 10^6 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int prime[1000001];
int main()
{
	ll t;
	cin>>t;
	
	prime[0]=prime[1]=1;
	for(int i=2;i*i<=1000000;i++)
	{
		if(!prime[i])
		{
			for(int j=(i*i);j<1000000;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	while(t--)
	{
		ll n;
		cin>>n;
		if(!prime[n])
		cout<<"Number is prime"<<endl;
		else
		cout<<"Number is not prime"<<endl;
		
	}
}
