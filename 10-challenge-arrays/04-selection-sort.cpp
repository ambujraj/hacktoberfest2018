#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, min,j,min_i;
	cin>>n;
	int a[n];
	// read
	for(int i=0;i<n;i++)
		cin>>a[i];
	// sort o(n^2)
	for(int i=0;i<n-1;i++){
		min_i = i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min_i]){
				min_i = j;
			}
		}
		// swap i with j-1;
		min = a[min_i];
		a[min_i] = a[i]; 
		a[i] = min;
	}

	// display
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	return 0;
}

/*
1. find min in array[0,n-1], [1,n-1], [2,n-1] ....
2. place it at begining [0], [1], [2] .....
3. repeat step 1 and 2 and reduce in 1 and increase in 2.

*/