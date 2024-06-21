#include<stdio.h>
main()
{   int x=0,y=1,sum,n,count;
    printf("n is the no. of the terms\n\n");printf("\n\n");
    printf("enter the value of n");printf("\n");
    scanf("%d",&n);
    for(count==3;count<=n;count++)
    {  sum=x+y;
       x=y;
       y=sum;
       printf("  %d  ",sum);
	}
}
