/*
Creatnx now wants to decorate his house by flower pots. He plans to buy exactly  ones.
He can only buy them from Triracle's shop. There are only two kind of flower pots available in that shop.
The shop is very strange. If you buy  flower pots of kind 1 then you must pay  and  if you buy  flower pots of kind 2.
Please help Creatnx buys exactly  flower pots that minimizes money he pays.

Input Format
The first line contains a integer  denoting the number of test cases.
Each of test case is described in a single line containing three space-separated integers .
Output Format
For each test case, print a single line containing the answer.

SAMPLE INPUT 
2
5 1 2
10 2 4

SAMPLE OUTPUT 
17
134
*/

#include <iostream>

using namespace std;

int main() {
	long long int T;
	cin >> T;										// Reading input from STDIN
	while(T--) {
	 long long int N, A, B;
	 cin>>N>>A>>B;
	 long long int x = (N*B)/(A+B);
	 long long int a1 = A*x*x + B*(N-x)*(N-x);
	 long long int a2 = A*(x+1)*(x+1) + B*(N-x-1)*(N-x-1);
	 if(a1<a2) cout<<a1<<endl;
	 else cout<<a2<<endl;
	    
	}
}

