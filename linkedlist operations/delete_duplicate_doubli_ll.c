#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *preptr;
    struct node *nextptr;
}*new;

int main(void)
{
    int n,i,j;
    printf("Enter the no of nodes you want");
    scanf("%i",&n);
    createnode(n);

    printf("The node with duplicate elements \n");
    displayList();

    printf("Node without duplicate elements \n");
    removeduplicate(n);
    printf("The node after removing duplicate elements is \n");
    displayList();
}

int createnode(int n)
{
    struct node *tmp,*fnnode;
    int i,data,num;
    printf("Enter the data in the first node : ");
    scanf("%i",&num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->preptr = NULL;
    new->nextptr = NULL;
    tmp = new;

    for(i=2;i<=n;i++)
    {
        fnnode = (struct node *)malloc(sizeof(struct node*));
        printf("Enter the data :");
        scanf("%i",&data);
        fnnode->data = data;
        fnnode->preptr = tmp;
        fnnode->nextptr = NULL;

        tmp->nextptr = fnnode;
        tmp = tmp->nextptr;
    }
}

int displayList()
{
    struct node *tmp;
    tmp = new;
    while(tmp!=NULL)
    {
        printf("Data is : %i \n",tmp->data);
        tmp = tmp->nextptr;
    }
}

int removeduplicate(int n)
{
    struct node *tmp,*delnode;
    tmp = new;
    int i,j;
    while(tmp != NULL)
    {

        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                tmp = tmp->nextptr;
                if(tmp->data == tmp->nextptr->data)
                {
                    delnode = (struct node *)malloc(sizeof(struct node));
                    delnode = tmp->nextptr;
                    tmp->nextptr = tmp->nextptr->nextptr;
                    tmp->nextptr->preptr = tmp;
                    free(delnode);
                }
            }
        }
    }
}
