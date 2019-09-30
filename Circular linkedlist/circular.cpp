#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* insert_at_beginning(Node* tail, int data){
    Node* temp = new Node();
    temp->data = data;
    Node* head = tail->next;
    tail->next = temp;
    temp->next = head;
    return tail;
}

Node* insert_at_end(Node* tail, int data){
    Node* temp = new Node();
    temp->data = data;
    Node* head = tail->next;
    tail->next = temp;
    temp->next = head;
    tail = temp;
    return tail;
}

Node* delete_at_beginning(Node* tail){
    if(tail == NULL){
        return NULL;
    }
    Node* temp = tail->next->next;
    delete tail->next;
    tail->next = temp;
    return tail;
}

Node* delete_at_end(Node* tail){
    Node* temp = tail;
    if(temp==NULL){
        return temp;
    }
    while(temp->next!=tail){
        temp = temp->next;
    }
    Node* temp2 = tail->next;
    delete tail;
    tail = temp;
    tail->next = temp2;
    return tail;
}

void print(Node* tail){
Node* temp = tail->next;
cout<<temp->data<<" ";
temp = temp->next;
while(temp!=tail->next){
    cout<<temp->data<<" ";
    temp = temp->next;
}}

int main()
{
    cout<<"ENTER THE ELEMENTS OF THE LINKED LIST AND TERMINATE THE LIST BY -1"<<endl;
    int n;
    cin>>n;
    Node* head = NULL;
    Node* tail = NULL;
    while(n!=-1){
            Node* temp = new Node();
            temp->data = n;
            temp->next = NULL;
        if(head==NULL){
            head = temp;
            tail = temp;
            tail->next = head;
        }
        else{
            tail->next = temp;
            tail = tail->next;
            tail->next = head;
        }
        cin>>n;
    }
    int ch;
    cout<<"CHOOSE YOUR CHOICE AND -1 TO TERMINATE"<<endl;
    cout<<"1)	Insertion of a node at beginning or at the end of list."<<endl;
    cout<<"2)	Deletion of a node at beginning or at the end of list."<<endl;
    cout<<"3)	Display the link list."<<endl;
    cin>>ch;
    while(ch!=-1){
        if(ch==1){
                cout<<"ENTER DATA"<<endl;
                int x;
                cin>>x;
                char a;
            cout<<"DO YOU WANT TO "<<endl;
            cout<<"a) INSERT AT THE BEGINNING"<<endl;
            cout<<"b) INSERT AT THE END"<<endl;
        cin>>a;
        if(a=='a'){
            tail = insert_at_beginning(tail, x);
        }
        if(a=='b'){
            tail = insert_at_end(tail, x);
        }  }
        if(ch==2){
                char a;
            cout<<"DO YOU WANT TO "<<endl;
            cout<<"a) DELETE AT THE BEGINNING"<<endl;
            cout<<"b) DELETE AT THE END"<<endl;
            cin>>a;
        if(a=='a'){
            tail = delete_at_beginning(tail);
        }
        if(a=='b'){
            tail = delete_at_end(tail);
        }
        }
        if(ch==3){
                cout<<"The current linked list is:  ";
             print(tail);
        }
        cout<<"Enter choice"<<endl;
        cin>>ch;
    }
}
