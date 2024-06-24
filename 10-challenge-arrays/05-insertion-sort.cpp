#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,j,key;
	cin>>n;
	int a[n];
	// read
	for(int i=0;i<n;i++)
		cin>>a[i];
	// sort o(n^2)
	for(int i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(a[j]>key and j>=0){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}

	// display
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}

/*

1. pick the 2nd element and place it to its position left of it. 

*/