#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *newNode(int x){
    struct node *temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct node *createLinkedList(int a[], int n){
    struct node *head, *current;
    if(n>0){
        head = newNode(a[0]);
        current = head;
    }
    for(int i=1; i<n; i++){
        current->next = newNode(a[i]);
        current = current->next;
    }
    return head;
}

struct node *reverseList(struct node *head){
    struct node *prev=NULL, *current=head, *next=head->next;

    while(current){
        current->next=prev;
        prev=current;
        current=next;
        next=(current)?current->next:NULL;
    }
    return prev;
}

void printList(struct node *head){
    struct node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    struct node *head;

    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    head=createLinkedList(a,n);
    //printList(head);
    head=reverseList(head);
    printList(head);

    return 0;
}
