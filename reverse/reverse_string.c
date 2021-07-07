#include <stdio.h>
#include <string.h>

// Function prototype
void string_rev(char*, int);
void swap(char*, char*);

int main()
{
	char str[30];
	printf("Enter a string: ");
	scanf("%[^\n]", str);
	string_rev(str, strlen(str));
	printf("Reversed string: %s\n", str);
	return 0;
}


void string_rev(char A[], int n)
{
	for (int i = 0; i < n/2; ++i)
	{
		swap(&A[i], &A[n-1-i]);
	}
}

void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}