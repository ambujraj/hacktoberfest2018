
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nextptr;
}*new;

int main(void)
{
    int n,i,j;
    printf("ENter the no of elments you want to insert : ");
    scanf("%i",&n);
    createnode(n);

    printf("THe node without delteion is \n");
    displaynode();

    printf("THe node after removal is \n");
    MiddleNodeDeletion();
    displaynode();
}
int createnode(int n)
{
    struct node *tmp,*fnnode;
    printf("Enter the first element");
    scanf("%i",&num);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->nextptr = NULL;
    tmp = new;
    for(i=2;i<=n;i++)
    {
        printf("Enter the data : ");
        fnnode = (struct node *)malloc(sizeof(struct node));
        fnnode->data = num;
        fnnode->nextptr = NULL;

        tmp->nextptr = fnnode;
        tmp = tmp->nextptr;
    }
}
int MiddleNodeDeletion()
{
    struct node *tmp,*prenode;
    printf("Enter the pos to be delted from the middle");
    scanf("%i",&pos);
    if(pos==1 || pos < n)
    {
        printf("wrong input");
        MiddleNodeDeletion();
    }
    else
    {
        tmp = new;
        prenode = new;

        for(i=2;i<pos;i++)
        {
            prenode = tmp;
            tmp = tmp->nextptr;
            if(tmp == NULL)
            {
                break;
            }
        }
        if(tmp != NULL)
        {
            if(tmp == new)
                new = new->nextptr;
                prenode->nextptr = tmp->nextptr;
                tmp->nextptr = NULL;
                free(tmp);
        }
    }
}
int displaynode()
{
    printf("Data is : %i \n ",tmp->data)
    tmp = tmp->nextptr;
}
