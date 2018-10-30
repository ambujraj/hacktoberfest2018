#include <bits/stdc++.h>
using namespace std;

int stringdigit(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(isdigit(str[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	cout << "Please enter a phone number: ";
	string number;
	cin >> number;

	if(number.length() != 10 || !stringdigit(number))
	{
		cout << "Not a valid phone number" << endl;
		return 1;
	}


	cout << "is a valid phone number" << endl;
	return 0;
}
