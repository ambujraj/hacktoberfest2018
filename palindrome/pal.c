#include <stdio.h>
#define INIT_VALUE -1
int palindrome(char *str);
int main()
{
    char str[80];
    int result = INIT_VALUE;

    printf("Enter a string: \n");
    gets(str);
    result = palindrome(str);
    if (result == 1)
        printf("palindrome(): A palindrome\n");
    else if (result == 0)
        printf("palindrome(): Not a palindrome\n");
    else
        printf("An error\n");
    return 0;
}
int palindrome(char *str)
{
    /* Write your code here */
    char *p;
    int isPalindrome, i, j, size = 0;
    p = str;

    while (*p != '\0')
    {
        size++;
        p++;
    }

    j = size;

    for (i=0; i < size/2; i++)
    {
        if (str[i] == str[j-1])
            isPalindrome = 1;
        else
            isPalindrome = 0;

        j--;
    }

    return isPalindrome;
}
