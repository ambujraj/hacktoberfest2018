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
    struct node *head, *slow, *fast;

    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    head=createLinkedList(a,n);
    slow = fast = head;

    if(n%2==0)
        fast = fast->next;

    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;

    return 0;
}
