#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,count,n;
  cout<<"Enter the number of items (1<=X<=50): ";
  cin>>n;
	int list[n],rank_list[n],sort_list[n];


	cout<<"Enter the list elements: ";
	for(i=0; i<n; i++)
		cin>>list[i];

	/*Calculate the rank for each element in the arr_list*/

	for(i=0; i<n; i++)
	{
		for(j=0; j<i; j++)
		{
			if(list[i] >= list[j])
				rank_list[i]++;
			else
				rank_list[j]++;
		}
	}


	for(i=0; i<count; i++)
		sort_list[rank_list[i]] = list[i];

	printf("\nSorted listed according to the rank\n\t");
	for(i=0; i<count; i++)
		cout<<sort_list[i]<<" ";
cout<<"\n";

}
