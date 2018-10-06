#include <stdio.h>


int main()
{
	long long int n; // No. for which Factorial is required
	scanf("%lld", &n);
	long long int result = 1;
	while(n)
	{result*=n;
	n--;}
	printf("%lld\n", result);
	return 0;
}

