#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int val;
	struct _node*next;
}node;

node *makenode (int);
void print(node *);
node *insert(node*,int);
node *intersection(node *,node *);

void main()
{
	node *start1='\0',*start2='\0',*nd,*start='\0';
	int n;
	while(1)

	{
		printf("\nEnter the Number [0 to end] : ");
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		start1=insert(start1,n);
	}
	print(start1);
	while(1)
	{
		printf("\nEnter the Number [0 to end] : ");
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		start2=insert(start2,n);
	}
	print(start2);
	start=intersection(start1,start2);
	print(start);
}

node *makenode(int n)
{
	node *nd;
	nd=(node *)malloc(sizeof(node));
	nd->val=n;
	nd->next='\0';
	return nd;
}
void print(node *ptr)
{
	while(ptr)
	{
		printf("%d ",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}
node *insert(node *start,int n)
{
	node *ptr,*prv,*nd;
	for(ptr=start;ptr&&n>ptr->val;prv=ptr,ptr=ptr->next);

	nd=makenode(n);
	nd->next=ptr;
	if(ptr==start)
	{
		start=nd;
	}
	else
	{
		prv->next=nd;
	}
	return start;
}
node *intersection(node *s1,node *s2)
{
	node *start='\0',*ptr,*tmp;
	tmp=s2;
	ptr=start;
	while(s1)
	{
		while(s2)
		{
			if(s1->val==s2->val)
			{
				if(start=='\0')
				{
					start=s1;
					ptr=start;
					break;
				}
				else
				{
					ptr->next='\0';
					ptr->next=s2;
					ptr=ptr->next;
					break;
				}
			}
			s2=s2->next;
		}
		s2=tmp;
		s1=s1->next;
	}

	return start;

}
