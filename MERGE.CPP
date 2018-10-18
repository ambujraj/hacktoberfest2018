#include<iostream.h>
#include<conio.h>
void print(int ar[],int n);
void mergeSort(int ar[],int low,int high);
void merge(int ar[],int low,int mid,int high);
void main()
{
    clrscr();
    int ar[20],n,i;
    cout<<"Enter no. of elements."<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
	cin>>ar[i];
    }
    mergeSort(ar,0,n-1);
    cout<<"Sorted elements are:"<<endl;
    print(ar,n);
    getch();
}
void mergeSort(int ar[],int low,int high)
{
    int mid;
    if(low<high)
    {
	mid=(low+high)/2;
	mergeSort(ar,low,mid);
	mergeSort(ar,mid+1,high);
	merge(ar,low,mid,high);
    }
}
void merge(int ar[],int low,int mid,int high)
{
    int L[10],R[20],n1,n2,i,j,k;
    n1=mid-low+1;
    n2=high-mid;
    for(i=0;i<n1;i++)
	L[i]=ar[low+i];
    for(j=0;j<n2;j++)
	R[j]=ar[mid+j+1];
    i=j=0;
    k=low;
    while((i<n1)&&(j<n2))
    {
	if(L[i]<=R[j])
	{
	    ar[k]=L[i];
	    i++;
	}
	else
	{
	    ar[k]=R[j];
	    j++;
	}
	k++;
    }
    while(i<n1)
    {
	ar[k]=L[i];
	i++;
	k++;
    }
    while(j<n2)
    {
	ar[k]=R[j];
	j++;
	k++;
    }
}
void print(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
	cout<<ar[i]<<endl;
    }
}
