//factorial using recursion
#include <iostream>
using namespace std;
int factorial(int);

int main()
{
	int n;
	cin >> n;
	int fact = 1;
	for(int i = 1; i <=n; ++i)
	{
		fact *= i;
	}
	cout<<fact;
	return 0;
}
	
