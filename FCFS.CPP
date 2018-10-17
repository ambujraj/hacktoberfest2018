#include<stdio.h>
#include<conio.h>

void TurnArroundTime(int arr[],int p)
{       int j=0;
	int max;
	int tat=0;
	int wt=0;
	float totaltat=0,totalwt=0;

	for(j;j<p;j++)
	{
		tat=tat+arr[j];
		printf("The TurnAround time for p%d is %d\n",j,tat);
		wt=tat-arr[j];
		printf("The WaitingTime for p%d is %d\n\n",j,wt);
		totalwt=wt+totalwt;
		totaltat=tat+totaltat;
	}
	printf("The Average turn around time = %f\n",totaltat/p);
	printf("The Average Waiting time = %f\n",totalwt/p);
}

void main()
{       int p;
	printf("THE IMPLEMENTATION OF FCFS SYSTEM OF PROCESSING\n\n");

	printf("Enter number of processes ");

	scanf("%d",&p);
	int arr[50];
	printf("Enter Burst time for each process \n");
	for(int i=0;i<p;i++)
	{
		scanf("%d",&arr[i]);
	}
	TurnArroundTime(arr,p);

	getch();
	clrscr();
}