#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nextptr;
};

struct node *new;

int main(void)
{
    int i,j,k,n;
    printf("Enter the no of nodes you want : ");
    scanf("%i",&n);
    createnode(n);
    printf("The unsorted list is \n");
    displaynodes();

    printf("The sorted list is");
    sort();
    displaynodes();

    return 0;
}
int createnode(int n)
{
    struct node *tmp,*fnnode;
    int i,j,data;

    printf("Enter the data in the first node: ");
    scanf("%i",&data);
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->nextptr = NULL;
    tmp = new;
    for(i=2;i<=n;i++)
    {
        printf("Enter the data : ");
        scanf("%i",&data);
        fnnode = (struct node *)malloc(sizeof(struct node));
        fnnode->data = data;
        fnnode->nextptr = NULL;
        tmp->nextptr = fnnode;
        tmp = tmp->nextptr;
    }
}

int sort()
{
    struct node *list,*pass;
    list = new;
    int temp;
    for(;list->nextptr != NULL; list = list->nextptr)
    {
        for(pass=list->nextptr;pass!=NULL;pass=pass->nextptr)
        {
            if(list->data > pass->data)
            {
                temp = list->data;
                list->data = pass->data;
                pass->data = temp;
            }
        }
    }
}

int displaynodes()
{
    struct node *tmp;
    tmp = new;
    while(tmp != NULL)
    {
        printf("THe data is %i \n",tmp->data);
        tmp = tmp->nextptr;
    }
}
