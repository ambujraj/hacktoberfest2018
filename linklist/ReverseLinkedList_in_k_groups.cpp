#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 

struct Node *reverse (struct Node *head, int k) 
{ 
    struct Node* current = head; 
    struct Node* next = NULL; 
    struct Node* prev = NULL; 
    int count = 0;    
      
    /*reverse first k nodes of the linked list */ 
    while (current != NULL && count < k) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
      
    /* next is now a pointer to (k+1)th node  
       Recursively call for the list starting from current. 
       And make rest of the list as next of first node */
    if (next !=  NULL) 
       head->next = reverse(next, k);  
  
    /* prev is new head of the input list */
    return prev; 
} 

void push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 

    new_node->data  = new_data; 
    new_node->next = (*head_ref);     
    (*head_ref)    = new_node; 
} 
  
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
}     

int main(void) 
{ 
    
    struct Node* head = NULL; 
   
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head, 9); 
     push(&head, 8); 
     push(&head, 7); 
     push(&head, 6); 
     push(&head, 5); 
     push(&head, 4); 
     push(&head, 3); 
     push(&head, 2); 
     push(&head, 1);            
  
     printf("\nGiven linked list \n"); 
     printList(head); 
     head = reverse(head, 3); 
  
     printf("\nReversed Linked list \n"); 
     printList(head); 
  
     return(0); 
} 

