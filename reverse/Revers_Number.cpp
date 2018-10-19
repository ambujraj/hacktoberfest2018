#include<bits/stdc++.h>
using namespace std;

long int reversNumber(long int num)
{
	int temp,flag = 0;
	long int rNum;
	
	if(num < 0)
	{
		num = num * -1;
		flag = 1;
	}
	
	while(num>0)
	{
		temp = num % 10;
		rNum = (rNum * 10) + temp;
		num = num / 10;
	}
	
	return flag == 1?(rNum*-1):rNum;

}


int main()
{
	long int num = 123456789;
	
	cout<<reversNumber(num);

	return 0;
}
