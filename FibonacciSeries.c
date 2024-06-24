#include <stdio.h>
//main function
int main()
{
    //variable declaration
    int index, n, term_1 = 0, term_2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci Series is : ");

    for (index = 1; index <= n; index++)
    {
        printf("%d, ", term_1);
        nextTerm = term_1 + term_2;
        term_1 = term_2;
        term_2 = nextTerm;
    }
    return 0;
}
