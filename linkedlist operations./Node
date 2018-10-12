#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

struct Node* createNode( int n){
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode)
    {
	newNode->value = n;
        newNode->next = NULL;
    }
    return newNode;
}

int sizeofList(struct Node *head)
{
    int count;
    struct Node *curr;
    if(head==NULL)
        return 0;
    if(head->next==NULL)
        return 1;

    count=1;
    curr=head;
    while ( (curr = curr->next) != NULL )
        count++;

    return count;
}


void addNode(struct Node **head, int val){
    
    struct Node *newNode = createNode(val);
    struct Node *curr;

    if((*head)==NULL)
    {
        *head=newNode;
        (*head)->next=NULL;
    }
    
    else
    {
	curr = *head;
	while((curr->next)!=NULL)
	    curr=curr->next;
	curr->next=newNode;
    }   
}


void deleteNode(struct Node **head,int index){
    
    struct Node *tmp;
    struct Node *curr;
    int i;

    
    if(index>=sizeofList(*head))
        return;

    if(sizeofList(*head)==0)
        return;

    else if(sizeofList(*head)==1)
    {
        free(*head);
	*head=NULL;
        return;
    }

    else
    {
	if(index==0)
	{
	    curr=(*head)->next;
	    (*head)->next=NULL;
            free(*head);
	    *head=curr;	    
	}
	
	else
	{
	    curr=*head;
	    for(i=0;i<index-1;i++)
                curr=curr->next;
        
            tmp=curr->next;
    	    curr->next=tmp->next;
    	    tmp->next=NULL;
            free(tmp);
	}
    }

    return;
}

void printList(struct Node *head)
{
    int listSize=sizeofList(head);
    
    int i;
    struct Node *curr;
    if(listSize==0)
    {
	printf("Nothing to print!\n");
	return;
    }
    
    curr=head;
    for(i=0;i<listSize;i++)
    {
        printf("Node %d: %d\n",i, curr->value);
	curr=curr->next;
    }
}


int main(int argc, char* argv[])
{
    
    struct Node *head;

    head=NULL;
    printf("Initial list size: %d\n",sizeofList(head));
    printList(head);
    printf("\n");

    addNode(&head,10);
    addNode(&head,20);
    printf("List size after insertions: %d\n",sizeofList(head));
    printList(head);
    printf("\n");
    
    deleteNode(&head,0);
    printf("List size after deletion: %d\n",sizeofList(head));
    printList(head);
    printf("\n");

    deleteNode(&head,0);
    printf("List size after deletion: %d\n",sizeofList(head));
    printList(head);
    printf("\n");
    
    addNode(&head,30);
    printf("List size after insertion: %d\n",sizeofList(head));
    printList(head);
    printf("\n");

    return 0;
    
}
