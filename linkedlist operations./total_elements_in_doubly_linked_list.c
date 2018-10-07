#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nextptr;
    struct node *preptr;
}*new;

int main(void)
{
    int n;
    printf("Enter the no of elements you want in the linked list");
    scanf("%i",&n);
    createnode(n);

    printf("Printing the list");
    displaynodes();

    printf("The no of elements in the linked list is %i : ",n);
    return 0;
}
int createnode(int n)
{
    struct node *tmp,*fnnode;
    int i,num,data;
    printf("Enter the data in the first element");
    scanf("%i",&data);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->preptr = NULL;
    new->nextptr = NULL;
    tmp = new;
    for(i=2;i<=n;i++)
    {
        printf("Enter the data : ");
        scanf("%i",&num);
        fnnode = (struct node *)malloc(sizeof(struct node));
        fnnode->data = num;
        fnnode->preptr = tmp;
        fnnode->nextptr = NULL;

        tmp->nextptr = fnnode;
        tmp = tmp->nextptr;
    }
}
int displaynodes()
{
    struct node *tmp;
    tmp = new;
    while(tmp!=NULL)
    {
        printf("Data is : %i",tmp->data);
        tmp = tmp->nextptr;
    }
}
