// binary search for sorted array 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t;  //test cases
 	cin>>t;
	ll n;  //no of the element in the array
	cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	while(t--)
	{
		ll  x;  //element to be searched
		scanf("%d",&x);
		ll low=0;
		ll high=n-1;
		int flag=0;
		while(low<=high)
		{
			ll mid=low+(high-low)/2;

			if(arr[mid]==x)
			{
				flag=1;
				break;
			}
			else if(arr[mid]>x)
			{
				high=mid-1;
			}
			else
			low=mid+1;
		}

		if(flag)
		printf("Element Found\n");
		else
		printf("Element Not Found\n");
		
	}
	return 0;

}

