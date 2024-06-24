#include<iostream>
using namespace std;
#define MAX 1500

int multiply(int x, int res[], int size){
	int carry = 0, prod;
	for(int i=0;i<size;i++){
		prod = res[i]*x + carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry){ // for large number multiplication
		res[size] = carry%10;
		carry = carry/10;
		size++;
	}
	
	return size;
}

int factorial(int n){
	int res[MAX];
	int res_size = 1;
	res[0]=1;

	for(int i=2;i<=n;i++){
		res_size = multiply(i, res,res_size);
	}
	for(int i=res_size-1; i>=0;i--){
		cout<<res[i];
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	factorial(n);
	return 0;
}

/*
Problem: broken calculator.

*/