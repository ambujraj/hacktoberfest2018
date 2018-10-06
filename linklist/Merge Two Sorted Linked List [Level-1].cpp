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
    struct node *head=NULL, *current;
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

void printList(struct node *head){
    struct node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

struct node *mergeLists(struct node *head1, int n, struct node *head2, int m){
    int l=n+m;
    struct node *head=NULL, *current=NULL;

    if(head1 && head2){
        if(head1->data < head2->data){
            head=newNode(head1->data);
            head1=head1->next;
        }
        else{
            head=newNode(head2->data);
            head2=head2->next;
        }
        current=head;

        for(int i=1; i<l && head1 && head2; i++){
            if(head1->data <= head2->data){
                current->next=newNode(head1->data);
                head1=head1->next;
            }
            else{
                current->next=newNode(head2->data);
                head2=head2->next;
            }
            current=current->next;
        }
    }
    else if(head1){
        head=newNode(head1->data);
        head1=head1->next;
        current=head;
    }
    else if(head2){
        head=newNode(head2->data);
        head2=head2->next;
        current=head;
    }
    while(head1){
        current->next=newNode(head1->data);
        head1=head1->next;
        current=current->next;
    }
    while(head2){
        current->next=newNode(head2->data);
        head2=head2->next;
        current=current->next;
    }
    return head;
}

int main()
{
    int n,m;
    struct node *head1=NULL, *head2=NULL, *head;

    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    cin>>m;
    int b[m];
    for(int i=0; i<m; i++)
        cin>>b[i];

    head1=createLinkedList(a,n);
    head2=createLinkedList(b,m);
    head=mergeLists(head1, n, head2, m);
    printList(head);

    return 0;
}
