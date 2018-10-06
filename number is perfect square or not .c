#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    int iVar;
    float fVar;

    printf("Enter an integer number: ");
    scanf("%d",&num);

    fVar=sqrt((double)num);
    iVar=fVar;

    if(iVar==fVar)
        printf("%d is a perfect square.",num);
    else
        printf("%d is not a perfect square.",num);

    return 0;
}

