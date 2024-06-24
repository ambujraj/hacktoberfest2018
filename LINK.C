#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *link;
};
struct node *top=NULL,*temp,*start,*newnode;
void push();
void pop();
void peek();
struct node *getnode()
{
newnode=(struct node* )malloc(sizeof(struct node));
printf("enter value");
scanf("%d",&newnode->data);
newnode->link=NULL;
return(newnode);
}
void main()
{
int a;
clrscr();
printf("1 for push\n 2 for pop\n 3 for peek\n");
while(1)
{
printf("enter choice");
scanf("%d",&a);
switch(a)
{
case 1: push();
	break;
case 2 :pop();
      break;
case 3:peek();
      break;
case 4:exit(1);
       break;
default:printf("invalid");
}
}
getch();
}
void push()
{
newnode=getnode();
if(top==NULL)
top=newnode;
else
{
newnode->link=top;
top=newnode;
}
}
void pop()
{
if(top==NULL)
printf("empty");
else
{
temp=top;
top=temp->link;
temp->link=NULL;
free(temp);
}
}
void peek()
{
if(top==NULL)
printf("empty");
else
{
temp=top;
while(temp->link!=NULL)
{
printf("%d",temp->data);
temp=temp->link;
}
printf("%d",temp->data);
}
}