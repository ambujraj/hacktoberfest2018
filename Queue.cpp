#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int front=-1;
int rear=-1;
int insert(int);
int delet();
int display();
int a[10],n;
int main()
{
	int choice,n,ans;
	do
	{
		printf("1.Insert\n 2.Delete\n 3.Display\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the number\n");
					scanf("%d",&n);
					insert(n);
					break;
			case 2:delet();
					break;
			case 3:display();
					break;
			default:printf("Invalid choice\n");
		}
		printf("DO you want to continue?\n");
		ans=getch();
	}while(ans=='Y'||ans=='y');
}
int insert(int n)
{
	if(rear>=9)
		printf("Queue is full");
	else
		a[rear++]=n;
		return rear;
}
int delet()
{
	if((front==-1&&rear==-1)||front>rear)
		printf("Queue is empty\n");
 	else
		n=a[front++];
		printf("the deleted item is:%d\n",n);
		return front;
}
int display()
{
	int i;
	if(front==-1 && rear==-1)
		printf("Queue is empty\n");
	else
		for(i=front;i<rear;i++)
			printf("%d\n",a[i]);
}
