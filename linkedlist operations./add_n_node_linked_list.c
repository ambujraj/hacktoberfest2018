#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nextptr;
}*new;

int main(void)
{
    int n,an,sum;
    printf("Enter the no of nodes you want ");
    scanf("%i",&n);
    createnode(n);

    printf("Printing the unsorted nodes \n ");
    displayList();

    printf("Enter the no of nodes you want to add");
    scanf("%i",&an);
    sum = addnode(an,n);
    printf("The sum of those nodes is %i ",sum);
}
int createnode(int n)
{
    struct node *tmp,*fnnode;
    int num,i;

    new = (struct node *)malloc(sizeof(struct node));
    printf("Input the data for 1 st node : ");
    scanf("%i",&num);
    new->data = num;
    new->nextptr = NULL;
    tmp = new;

    for(i=2;i<=n;i++)
    {
        printf("Enter the data for the next node : ");
        scanf("%i",&num);
        fnnode = (struct node *)malloc(sizeof(struct node));
        fnnode->data = num;
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
        printf("Data is : %i \n ",tmp->data);
        tmp = tmp->nextptr;
    }
}

// look here

int addnode(int an,int n)
{
    struct node *tmp,*fsumnode,*tmp2;
    int len = 0,i=1;
    int sum = 0;
    tmp = new;
    while(len < an) // runs the nodes uptil the desired end
    {
        tmp = tmp->nextptr;
        len++;
    }
    while(i < an)// traverses from the desired no till end of the linked list
    {
        sum = tmp->data + sum;
        tmp = tmp->nextptr;
        i++;
    }
    return sum;
}

