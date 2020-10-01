#include <iostream>
using namespace std;

int main(){
	int n,max;
	cin>>n;
	int a[n];
	// read and find max
	cin>>a[0];
	max = a[0];
	for(int i=1;i<n-1;i++){
		cin>>a[i];
		if(max<a[i])
			max = a[i];
	}
	// show
	cout<<max<<endl;
	return 0;
}

/*
o(1) space


*/


