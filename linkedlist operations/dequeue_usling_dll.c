#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *preptr;
    struct node *nextptr;
}*head = NULL,*tail = NULL;

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->nextptr = newnode->preptr = NULL;
    return(newnode);
}

int createSentinels()
{
    head = createNode(0);
    tail = createNode(0);
    head->nextptr = tail;
    tail->preptr = head;
}

int enqueueAtFront(int data)
{
    struct node *newnode,*temp;
    newnode = createnode(data);
    temp = head->nextptr;
    head->nextptr = newnode;
    newnode->preptr = head;
    newnode->nextptr = temp;
    temp->preptr = newnode;
}

int enqueueAtRear(int data)
{
    struct node *newnode,*temp;
    newnode = createnode(data);
    temp = tail->preptr;
    tail->preptr = newnode;
    newnode->nextptr = tail;
    newnode->preptr = temp;
    temp->nextptr = newnode;
}

int dequeueAtFront()
{
    struct node *temp;
    if(head->nextptr == tail)
    {
        printf("Queue is empty \n");
    }
    else
    {
        temp = head->nextptr;
        head->nextptr = temp->nextptr;
        temp->nextptr->preptr = head;
        free(temp);
    }
    return;

}

int dequeueAtRear()
{
    struct node *temp;
    if(tail->preptr == head)
    {
        printf("Queue is empty \n");
    }
    else
    {
        temp = tail->preptr;
        tail->preptr = temp->preptr;
        temp->preptr->nextptr = tail;
        free(temp);
    }
    return;
}

int main()
{
    int data,ch;
    createSentinels();
    while(1)
    {
        printf(" 1. Enqueue at front \n 2. Enqueue at rear \n");
        printf("3. Dequeue at front \n 4. Dequeue ate rear \n");
        printf("5. Display \n 6. Exit \n");
        printf("Enter your choice");
        scanf("%i",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data to insert front front");
                scanf("%i",&data);
                enqueueAtFront(data);
                break;
            case 2:
                printf("Enter ur data to insert from rear");
                scanf("%i",&data);
            case 3:
                dequeueAtFront();
                break;
            case 4:
                dequeueAtRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Pls enter correct option \n");
                break;
        }
    }
    return 0;
}
