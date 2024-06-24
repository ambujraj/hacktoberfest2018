#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],key,i,n,low,high,mid;
clrscr();
printf("enter the value of n");
scanf("%d",&n);
printf("enter the values");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the value of key");
scanf("%d",&key);
low=0;
high=n-1;
while(low<=high)
{
mid=(low+high)/2;
if(key<a[mid])
high=mid-1;
else if(key>a[mid])
low=mid+1;
else
{
printf("%d is in the position %d",key,mid);
break;
}
}
if(low>high)
{
printf("key not found");
}
getch();
}