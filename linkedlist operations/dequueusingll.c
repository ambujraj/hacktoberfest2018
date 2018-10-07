#include<stdio.h>

#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*rear,*front;

void delqueue()
{
    struct node *temp, *var=rear;
    if(var==rear)
    {
        rear = rear->next;
        free(var);
    }
    else
    {
        printf("\n Queue empty");
    }
}
void push(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data = value;
    if(front == NULL)
    {
        front=temp;
        front->next=NULL;
        rear=front;
    }
    else
    {
        front->next=temp;
        front = temp;
        front->next = rear;
    }
}
void display()
{
    struct node *var=rear;
    if(var!=NULL)
    {
        printf("\n Elements are as: ");
        while(var!=front)
        {
            printf("%i",var->data);
            var=var->next;
        }
        if(var==front)
        {
            printf("%i",var->data);
        }
    }
    else
    {
        printf("Queue is empty");
    }
}

int main(int argc, char *argv[])
{
    int i=0;
    front=NULL;
    printf("1. Push to queue \n");
    printf("2. Pop from queue \n");
    printf("3. DIsplay Data of QUeue \n");
    printf("4. Exit \n");
    while(1)
    {
        printf("\n CHoose option: ");
        scanf("%i",&i);
        switch(i)
        {
            case 1:
                int value;
                printf("\n ENter a valueber to push into que");
                scanf("%i", &value);
                push(value);
                display();
                break;
            case 2:
                delqueue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            defualt:
                printf("\nWrong choice for operation");
        }
    }
}
