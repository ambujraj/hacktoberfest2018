// MANCHESTER UNITED >>>>> BARCELONA
#include <iostream>

using namespace std;

class node
{
	int info;
	node* next;
public:
	node* enqueue(node*);
	node* deque(node*);
	node* display(node*);
};
node* node::enqueue(node* start)
{
	node* temp;
	cout<<"enqueue...\n";
	if(start==NULL)
	{
		cout<<"Queue was empty..Entering first element..\n";
		temp = new node;
		cout<<"Enter info..\n";
		cin>>temp->info;
		temp->next = NULL;
		start = temp;
		temp = NULL;
	}
	else
	{
		node* temp1;
		temp = start;
		while(temp->next)
		{
			temp = temp -> next;
		}
		temp1 = new node;
		temp1 -> next = NULL;
		cout<<"Enter information..\n";
		cin>>temp1->info;
		temp -> next = temp1;
		temp=temp1=NULL;
	}
	return start;
}
node* node::deque(node* start)
{
	node* temp;
	cout<<"Deleting..\n";
	if(start==NULL)
	{
		cout<<"Queue empty..\n";
		return start;
	}
	else if(start->next == NULL)
	{
		cout<<"Single element present..\n";
		cout<<"Data deleted is.."<<start->info<<"\n";
		delete start;
		start = NULL;
		return start;
	}
	else 
	{
		temp = start;
		start = start -> next;
		cout<<"Element deleted is.."<<temp->info<<" "<<"\n";
		delete temp;
		return start;
	}
}
node* node::display(node* start)
{
	node* temp;
	if(start==NULL)
	{
		cout<<"Queue empty..\n";
		return start;
	}
	else
	{
		temp = start;
		while(temp)
		{
			cout<<"  "<<temp->info<<" ";
			temp = temp -> next;
		}
		cout<<"\n";
		temp = NULL;
		return start;
	}
}
int main()
{
	node* start = NULL;
	node n;
	int ch=1,ch1;
	while(ch)
	{
		cout<<"\n\nEnter   1.enqueue\n\t2.dequeue\n\t3.display\n\t4.Exit\n\n";
		cin>>ch1;
		switch(ch1)
		{
			case 1: cout<<"enqueue..\n";
			start = n.enqueue(start);
			break;
			case 2: cout<<"deque..\n";
			start = n.deque(start);
			break;
			case 3: cout<<"Displaying..\n";
			start = n.display(start);
			break;
			case 4: cout<<"Exit..\n";
			ch=0;
			break;
		}
	}
}