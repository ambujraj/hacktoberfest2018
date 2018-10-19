#include <iostream.h>
#include <conio.h>
void linear(int ar[],int n,int x);
void main()
{
    clrscr();
    int ar[20],n,x;
    cout<<"Enter no. of elements:"<<endl;
    cin>>n;
    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
    {
	cin>>ar[i];
    }
    cout<<"Enter no. to be searched:"<<endl;
    cin>>x;
    linear(ar,n,x);
    getch();
}
void linear(int ar[],int n,int x)
{
    int flag=0,i;
    for(i=0;i<n;i++)
    {
	if(ar[i]==x)
	{
	    flag=1;
	    break;
	}
    }
    if(flag==0)
    {
        cout<<"Number not found.";
    }
    else
    {
        cout<<"Desired no. found on position "<<(i+1);
    }
}
