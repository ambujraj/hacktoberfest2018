#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,m,carry=0,rem,sum ,max;
	cin>>n;
	int a[n];
	// inter two arrays
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	max = (m>=n)?m:n;
	int c[max+1] ={0};

	for(int i=0,j=0; i<min(m,n); i++,j++){
		sum = a[n-i-1] + b[m-i-1] + carry;
		rem = sum%10;
		c[max-i] =rem;
		carry = sum/10;
	}
	//sum remaining
	for(int i=max-(min(m,n));i>0;i--){
		if(m>=n)
			sum = b[i-1] + carry;
		else
			sum = a[i-1] + carry;
		rem = sum%10;
		c[i] =rem;
		carry = sum/10;
	}
	c[0] = carry;


	// /print 
	if(c[0]!=0){
		cout<<c[0]<<", ";
	}
	for(int i=1;i<max+1;i++){
		cout<<c[i]<<", ";
	}
	cout<<"END\n";
	return 0;
}

/*



*/