//To implement the concept of Non-Attacking Queen Problem
/* Designed the output and Coded 
		By--- Sagnik Chattopadhyaya
		Github-- sagnik20
		For more codes and coding help follow me on 
		Instagram-- @sagnik.20
		*/

#include<stdio.h>
#include<math.h>


void queen(int,int,int*,int*);
int check(int,int,int*);
void display(int*,int);


void main()
{
	int n,i;
	printf("Enter the number of Queens");
	scanf("%d",&n);
	int a[n];
	int count = 0;
	for(i=0;i<n;i++)
		a[i]=-1;
	queen(n,0,a,&count);
	printf("Count : %d\n", count);
}


void queen(int n,int r,int *a,int *count)
{
	int c;
	for(c=0;c<n;c++)
	{
		if(check(r,c,a)==0) 
		{
			a[r]=c;
			if(r==n-1){
				++*count;
				display(a,n);
			}
			else
				queen(n,r+1,a,count);
		}
	}
}



int check(int r,int c,int *a)
{
	int i;
	for(i=0;i<r;i++)
		if(a[i]==c)
			return 1;
	for(i=0;i<r;i++)
		if((r-i)==abs(a[i]-c))
			return 1;
	return 0;
}


void display(int *a, int n)
{
	int i, j,c1=65,c2=1;

	printf("Chess board -\n   ");
	for(i=0;i<n;i++)
		printf("  %c ",c1++);
	printf("\n   ");

	for(i=0;i<n;i++)
		printf("  _ ");
	printf("\n");
	
	for(i = 0; i < n; ++i)
	{
		printf("%d  ",c2++);
		for(j = 0; j < n; ++j)
		{
			if(a[j] == i){
				printf("| Q ");
			}
			else
				printf("| _ ");
		}

		printf("|\n");
		
	}
	printf("\n");
}
