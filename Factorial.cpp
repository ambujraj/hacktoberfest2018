/* create a factorial function for long integers*/
#include <iostream.h>
using namespace std;
int main(){
	int i,n;
	unsigned long long fact=1;// gives factorial of large numbers 
	cin>>n;
	for(i=1;i<=n;i++){
		fact =fact *i;
	}
	cout<<fact<<endl;
}
