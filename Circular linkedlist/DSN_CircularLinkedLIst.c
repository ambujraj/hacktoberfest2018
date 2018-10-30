#include<stdlib.h>
#include<stdio.h>

struct circularNode
{
    int data;
    struct circularNode* link;
};

struct circularNode* createnode(int a){
    struct circularNode* newnode = (struct circularNode*)malloc(sizeof(struct circularNode));

    newnode->data=a;
    newnode->link=NULL;

    return newnode;
};

void show(struct circularNode* head){
    struct circularNode* temp=head;
    if(head==NULL){
        return;
    }
    do{
        printf("%d ",temp->data);
        temp=temp->link;
    }while(temp!=head);
}

void insert_front(struct circularNode** head,int a){
    struct circularNode *p = *head;
    struct circularNode* newnode = (struct circularNode*)malloc(sizeof(struct circularNode));
    newnode->data = a;

    if(*head==NULL){
        *head=newnode;
        newnode->link=NULL;
    }

    newnode->link=p->link;
    (*head)=newnode;

}

void insert_end(struct circularNode** head,int a){
    struct circularNode *p;
    struct circularNode * newnode = (struct circularNode*)malloc(sizeof(struct circularNode));
    p=*head;
    newnode->data=a;
    while(p!=*head){
        p=p->link;
    }
    if(*head==NULL){
        *head=newnode;
    }
    newnode->link=*head;
    p->link=newnode;
}


int main()
{
    struct circularNode* a = createnode(7);
    insert_front(&a, 5);
    show(a);
}
