#include <iostream>
using namespace std;

int main()
{
	char l[200];
	int counter[26],i=0,k=0;
	for(i=0;i<26;i++)	counter[i]=0;
	cout<<"Enter string to be checked for pangram : "<<endl;
	gets(l);
	for(i=0;l[i]!='\0';i++)
	{
		if((l[i]>=65 && l[i]<=90) || (l[i]>=97 && l[i]<=122))
		{
			if(l[i]>=65 && l[i]<=90)	k=int(l[i]+32);
			else	k=int(l[i]);
			counter[k-97]++;
		}
	}
	for(i=0;i<26;i++)	
	{
		if(counter[i]==0)	
		{
			cout<<"The given sentence is not a pangram."<<endl;
			return 0;
		}
	}
	cout<<"The given sentence is a pangram."<<endl;
	return 0;
}