#include <iostream>
using namespace std;

int main(){
	int n, k,count=0;
	cin>>n;
	int a[n], b[n];
	int fa[n]={0}, fb[n]={0};
	// read and calculate frequency
	for(int i=0;i<n;i++){
		cin>>a[i];
		fa[a[i]-1]++;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		fb[b[i]-1]++;
	}

	//find intersection
	for(int i=0;i<n;i++){
		k = min(fa[i], fb[i]);
		for(int j=0; j<k; j++){
			a[count] = i+1;
			count++;
		}
	}
	// print 
	cout<<"[";
	for(int i=0; i<count; i++){
		if(i==count-1)
			cout<<a[i];
		else
			cout<<a[i]<<", ";
	}
	cout<<"]\n";
	return 0;
}

/*

o(n) space


*/