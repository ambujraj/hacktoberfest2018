#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*start;

node * create(int value)
{
	struct node *temp;
	temp = new(struct node);
	if(temp==NULL)
	{
		cout<<"Memory not alloacted";
		return 0;		
	}
	else
	{
		temp->data=value;
		temp->next=NULL;
		return temp;	
	}
}

void insert_beg()
{
	int value;
	cout<<"Enter value to be inserted: ";
	cin>>value;
	struct node *temp,*p;
	temp=create(value);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;	
	}
	else
	{
		p=start;
		start=temp;
		start->next=p;	
	}
	cout<<"Element inserted at begining\n";
}

void insert_last()
{
	int value;
	cout<<"Enter value to be inserted: ";
	cin>>value;
	struct node *temp,*p;
	temp=create(value);
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;	
	}
	temp->next=NULL;
	p->next=temp;
	cout<<"Element inserted at last\n"; 
}

void insert_pos()
{
	int value,pos,c=0,i;
	cout<<"Enter value to be inserted: ";
	cin>>value;
	struct node *temp,*p,*t1;
	temp=create(value);
	cout<<"Enter position";
	cin>>pos;
	p=start;
	while(p!=NULL)
	{
		p=p->next;
		c++;	
	}
	if(pos==1)
	{
		if(start==NULL)
		{
			start=temp;
			start->next=NULL;	
		}	
		else
		{
			t1=start;
			start=temp;
			start->next=t1;
		}
	}
	else if(pos>1 && pos<=c)
	{
		p = start;
		for(i=1;i<pos;i++)
		{
			t1=p;
			p=p->next;	
		}	
		t1->next=temp;
		temp->next=p;
	}
	else
		cout<<"Invalid Position";
		
}
void display()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<"List is empty";
		return;	
	}
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;	
	}
	cout<<"NULL\n";
}

int main()
{
	int ch,nodes,element,pos,i;
	start=NULL;
	while(1)
	{
		cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"8.Display Linked List"<<endl;
		cout<<"Enter ur choice";
		cin>>ch;
		switch(ch)
		{
			case 1: insert_beg();
					break;
			case 2: insert_last();
					break;
			case 3: insert_pos();
					break;
			case 8: display();
					break;
			default:exit; 
					break;	
		}	
	}	
	return 0;
}
