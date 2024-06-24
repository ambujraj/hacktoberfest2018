#include<iostream>
#include<climits>
using namespace std;
int main(){
	// median to sorted array
	int n, i, j, k;
	cin>>n;
	int a[n+1], b[n+1], c[2*n];
	// fill array
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	// add inf at end
	a[n]=INT_MAX;
	b[n]=INT_MAX;
	// merge array
	i = 0;
	j = 0;
	k = 0;
	while(i<=n and j<=n){
		if(a[i]<=b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	// find median and show
	cout<<(c[n-1]+c[n])/2<<endl;

	return 0;
}

/*
Given n and two arrays of size 2.
find median after merging
Method 1: o(n)
	merge the array and sort.
	as size of array is even find so add middle two element and divide by 2.

*/