#include <iostream>
using namespace std;
int factorial(int);

int main()
{
	int n;
	cin >> n;
	cout << "Calculated factorial is :" << factorial(n);
}

int factorial(int n)
{
	if (n==0) {
		return 1;
	}

  	return n * factorial(n-1);
}
	
