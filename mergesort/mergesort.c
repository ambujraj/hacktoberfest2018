#include<stdio.h>
#include<conio.h>
void mergesort(int a[],int ,int );
void merge(int a[],int ,int ,int ,int );
void main()
{ 
 int a[],n,i;
 clrscr();
 printF("Enter the value for n:");
 scanf("%d",&n);
 printf("Enter the values to be sorted\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 mergesort(a,0,n-1);
 printf("sorted elements are\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t",a[i]);
 }
 getch();
}
void mergesort(int a[],int i,int j)
{
 int mid;
 if(i<j)
 {
  mid=(i+j)/2;
  mergesort(a,i,mid);
  mergesort(a,mid+1,j);
  merge(a,i,mid,mid+1,j);
 }
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
 int temp[20],i,j,k;
 i=i1;
 j=i2;
 k=0;
 while(i<=j1&&j<=j2)
 {
  if(a[i])<a[j])
  {
   temp[k++]=a[i++];
  }
  else
  { 
   temp[k++]=temp[j++];
  }
 }
 while(i<=j1)
 {
  temp[k++]=a[i++]
 }
 for(i=i1,j=0;i<=j2;i++,j++)
 {
  a[i]=temp[j];
 }
}