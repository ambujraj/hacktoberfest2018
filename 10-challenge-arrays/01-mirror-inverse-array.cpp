#include <iostream>
#include <vector>
using namespace std;

int method2(){
	int n;
	cin>>n;
	int v[n],a[n];
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		
		if(v[i]!=a[v[v[i]]]){
			cout<<"false\n";
			return 0;
		}
	}
	cout<<"true\n";
	return 0;
}


int main(){
	int n;
	cin>>n;
	int v[n],a[n];
	for(int i=0;i<n;i++){
		cin>>v[i];
		a[i]=v[i];
	}
	// inverse
	for(int i=0;i<n;i++){
		v[v[i]]=i;
	}

	for(int i=0;i<n;i++){
		if(v[i]!=a[i]){
			cout<<"false\n";
			return 0;
		}
	}
	cout<<"true\n";
	return 0;
}

/*

inverse is swapping index with value of array.


*/