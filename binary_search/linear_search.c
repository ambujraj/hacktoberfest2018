#include <stdio.h>
#include <stdlib.h>

void main()
{
   int n,i,j,c=0;
   printf("Enter the size of array \n");
   scanf("%d",&n);
   int a[n];
   printf("Enter the elements of the array \n");
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   printf("Enter the search element \n");
    scanf("%d",&j);
   for(i=0;i<n;i++)
   {
       if(a[i]==j)
       {
           c++;
           break;
       }
   }
   if(c>0)
    printf("Search element found in position %d",i+1);
   else
    printf("Search element not found");
}
