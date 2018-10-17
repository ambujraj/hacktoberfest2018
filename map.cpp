#include<iostream>
#include<map>
using namespace std;



int main()
{
	map<string,int> m;
	
	//copying an array into a map
	int arr[11] = {12,14,15,16,17,17,16,60,12,1,56};
	map<int,int> map1;
	for(int i=0;i<11;i++)
	{
		map1[arr[i]]++;
	}
	cout<<endl<<map1[16];
	
	cout<<endl<<"displaying the original map first"<<endl;
	for(map<int, int>::const_iterator it = map1.begin(); it != map1.end(); it++)
	{
		cout<<endl<<it->first<<"   "<<it->second;
		}
}
