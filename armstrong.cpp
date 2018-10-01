/*A program to find the armstrong of a number*/

#include <iostream.h>
#include <math.h>
using namespace std;

int main(){
	int number, originalnumber, remainder,result=0,n=0;
	cout<<"enter a number"<<endl;
	cin>>number;
	originalnumber = number;
	while(originalnumber!=0){
		originalnumber/=10;
		++n;
	}
	originalnumber=number;
	while(originalnumber!=0){
		remainder=originalnumber%10;
		result+=pow(remainder,n);
		originalnumber/=10;
	}
	(result==number)?cout<<"armstrong":cout<<"not armstrong";
	return 0;
}

