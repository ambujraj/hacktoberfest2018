#include<iostream>
#include <climits>
using namespace std;

int max_subarray(int arr[], n){
	
}

int main(){
	int t,n;
	cin>>t;
	while(t--){ 
		int n;
    	cin>>n;
	    int arr[n]; // input array
	    int inc[n]; // sub array length at i, non-decreasing, left to right
	    int dec[n]; // sub array length at i, non-increasing, right to left
	    for(int i=0;i<n;i++)
	    	cin>>arr[i];

	    inc[0]=1;
	    dec[n-1]=1;

	    for(int i=1;i<n;i++)
	    	inc[i]=(arr[i]>=arr[i-1])?inc[i-1]+1:1;

	    for(int i=n-2;i>=0;i--)
	    	dec[i]=(arr[i]>arr[i+1])?dec[i+1]+1:1;
	    
	    int maximum=inc[0]+dec[0]-1;
	    for(int i=1;i<n;i++) 
	    	maximum=max(maximum,inc[i]+dec[i]-1);

	    cout<<maximum<<endl;
	}
	return 0;
}

/*
Note: Re-visit again.
Problem: Maximum length Biotonic Subarray.

Input:
2
6
12 4 78 90 45 23
4
40 30 20 10

Output:
5
4

if(input[i]>input[j]&&inc[i]<(inc[j]+1))
    inc[i]=inc[j]+1;
*/