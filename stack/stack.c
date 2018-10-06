#include<stdio.h>
#include<stdlib.h>

typedef struct node {
int data;
struct node *next;
}node;

typedef struct//implementation of stack
{
	node *head;
}STACK;


void init(STACK *s)
{
	s->head=NULL;
}
int isempty(STACK s)
{
	if(s.head==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(STACK *s, int data)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->next=s->head;
	newnode->data=data;
	s->head=newnode;
}

int pop(STACK *s)
{
	if(isempty(*s))
	{
		printf("STACK UNDERFLOW!!!\n");
		return -1;
	}
	node *p=s->head;
	s->head=(s->head)->next;
	int temp=p->data;
	free(p);
	return temp;
}

int peep(STACK s)
{
	if(isempty(s))
	{
		printf("STACK UNDERFLOW!!!\n");
		return -1;
	}
	return s.head->data;
}

void display(STACK s)
{
	if(isempty(s))
	{
		printf("STACK UNDERFLOW!!!\n");
		return;
	}
	node *p=s.head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("\n");
}


int main()
{
	STACK *s;
	init(s);
	int option,val;
	do
	{
		printf("\n 1.PUSH");
		printf("\n 2.POP");
		printf("\n 3.PEEP");
		printf("\n 4.display");
		printf("\n 5.EXIT");
		printf("\n\nenter your choice: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1: printf("enter the value to be pushed: ");
        	scanf("%d", &val);
			push(s,val);
			break;
		case 2: val= pop(s);
        	printf("the value popped is: %d", val);
			break;
		case 3: val=peep(*s);
        	printf("The Top of the stack is: %d", val);
			break;
		case 4: display(*s);
        	break;
		}
	} while(option != 5);
}
