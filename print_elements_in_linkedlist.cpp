#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void Print(struct Node *n)
{	int length=0;
	while (n!=NULL)
	{
		n->data;
	
	
		length++;
		if (length==1)
		cout<<n->data;
	
		n = n->next;	
	 } 
	
}

int main()
{
	struct Node* head =NULL;
	struct Node* second =NULL;
	struct Node* third =NULL;
	
	head = (struct Node*)malloc (sizeof(struct Node));
	second = (struct Node*)malloc (sizeof(struct Node));
	third = (struct Node*)malloc (sizeof(struct Node));
	
	
  head->data = 10;
  head->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = NULL;
                
  Print(second);
	
  return 0;
}
