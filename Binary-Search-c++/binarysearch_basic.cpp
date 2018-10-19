#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, i, arr[50], el, low, high, mid;
	cout << "Enter size of list:";
	cin >> n;
	cout << "Enter elements :";
	for (i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter element to be searched:";
	cin >> el;
	low = 0;
	high = n-1;
	mid = (low+high)/2;
	while (low <= high)
	{
		if(arr[mid] < el)
		{
			low = mid + 1;

		}
		else if(arr[mid] == el)
		{
			cout << el <<" found at location " << mid <<"\n";
			break;
		}
		else
		{
			 high = mid - 1;
		}
		mid = (low + high)/2;
	}
	if(low > high)
	{
		cout << "Not found! " << el << " is not present in the list.";
	}

	return 0;
}
