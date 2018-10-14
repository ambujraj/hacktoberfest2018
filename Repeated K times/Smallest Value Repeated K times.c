//smallest element present in array exactly K times
#include <stdio.h>
 
int main()
{   
    int n,i,j,k,flag = 0;

    printf("Enter number elements in your array: ");

    scanf("%d",&n);
 
    int a[n],max = -1;
 
    printf("Enter array elements: ");

    for(i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
         if(a[i]>max)
         {
              max = a[i];
         }
    }
    

    int count[max+1];

    for(j=0;j<max+1;j++)
    {
        count[j] = 0;
    }   
 
    printf("Enter value of K: ");

    scanf("%d",&k);
 
    for(j=0;j<n;j++)
    {
        count[a[j]]++;
    }

    for(i=0;i<max+1;i++)
    {
        if(count[i]==k)
        {
            flag = 1;
            printf("Required element is %d\n",i);
            break;
        }
    }

    if(flag==0)
        printf("No such element found\n");

    return 0;
}
