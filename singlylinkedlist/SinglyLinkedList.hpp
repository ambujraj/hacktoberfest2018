#include<iostream>
using namespace std;

template <typename Key,typename Value>
struct node{
  Key key;
  Value data;
  node* next;
};

template <typename Key,typename Value>
class SinglyLinkedList{
  private:
    node<Key,Value> *head,*tail;

  public:
    SinglyLinkedList(){
      head=NULL;
      tail=NULL;
    }
    void insert_front(const Key& key, const Value& value);
    void insert_end(const Key& key, const Value& value);
    void remove();
    void traverse();
};

template <typename Key,typename Value>
void SinglyLinkedList<Key,Value>::insert_front(const Key& key, const Value& value){
  node<Key,Value> *temp=new node<Key,Value>;
  temp->key=key;
  temp->data=value;
  temp->next=NULL;

  if(this->head==NULL){
    this->head=temp;
    this->tail=temp;
  }
  else{
    temp->next=this->head;
    this->head=temp;
  }
}

template <typename Key,typename Value>
void SinglyLinkedList<Key,Value>::insert_end(const Key& key, const Value& value){
  node<Key,Value> *temp=new node<Key,Value>;
  temp->key=key;
  temp->data=value;
  temp->next=NULL;

  if(this->head==NULL){
    this->head=temp;
    this->tail=temp;
  }
  else{
    this->tail->next=temp;
    this->tail=temp;
  }
}

template <typename Key,typename Value>
void SinglyLinkedList<Key,Value>::remove(){

  if(this->head==NULL){
    cout<<"List is Empty\n";
    return;
  }

  node<Key,Value> *temp;
  temp=this->head;
  this->head=temp->next;
  delete temp;
}

template <typename Key,typename Value>
void SinglyLinkedList<Key,Value>::traverse(){

  node<Key,Value> *temp=this->head;
  if(temp==NULL){
    cout<<"List is Empty\n";
    return;
  }
  while(temp!= NULL){
     cout<<temp->key<<":"<<temp->data<<" ";
     temp=temp->next;
  }
  cout<<"\n";
}
