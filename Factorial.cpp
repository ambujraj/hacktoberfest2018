//faktorial menggunakan fungsi rekursif
#include <iostream>
using namespace std;
int faktorial(int);

int main()
{
	int n;
	cin >> n;
	cout << "Faktorial dari angka tersebut adalah  :" << factorial(n);
}

int faktorial(int n)
{
	if (n==0) {
		return 1;
	}

  	return n * faktorial(n-1);
}
	
