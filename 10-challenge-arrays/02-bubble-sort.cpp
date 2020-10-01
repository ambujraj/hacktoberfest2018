#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]>a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] =t;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	cout<<"\n";
	return 0;
}

/*

swap alternate


*/