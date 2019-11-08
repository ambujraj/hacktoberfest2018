#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

int fib(int n,int m)
{
   
   return (m+n);
}

void main ()
{
    system("cls");
	int n,a,b,c,i;
    char ch;
	do
	{
	cout<<"generate fibonacci series upto how many numbers?(>=2):";
	cin>>n;
	cout<<1<<" "<<1;

    a=1;
	b=1;
	for(i=0;i<n-2;i++)
	{   c=fib(a,b);
		cout<<" "<<c;
		a=b;
		b=c;
	}
	cout<<"\ndo you want to enter again(y/n)?:";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
    getch();
}

