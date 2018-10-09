#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *ptr = NULL;
struct node *new = NULL;

void insertfront()
{
    new = (struct node*)malloc(sizeof(struct node)); 
    printf("\nEnter data:\n");
    scanf("%d",&new -> data);
    if( head == NULL)    
        new -> next = NULL;       
    else
        new -> next = head;      
    head = new;      
    printf("\nNew node inserted\n");  
}

void insertback()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:\n");
    scanf("%d",&new -> data);
    if( head == NULL) 
        head = new;          
    else
    {
        ptr = head;
        while(ptr -> next != NULL)
            ptr = ptr -> next;
        ptr -> next = new;       
    }   
    new -> next = NULL;
    printf("\nNew node inserted\n"); 
}

void insertspecific()
{
    int search,flag=0;
    if( head == NULL) 
    {
        printf("\nLinked list empty\n");
        return;
    } 
    ptr = head;
    printf("\nEnter search data:\n");
    scanf("%d",&search);
    while(ptr != NULL)
    {
        if( ptr -> data == search)
        {
            flag = 1;
            new = (struct node*)malloc(sizeof(struct node)); 
            printf("\nEnter data:\n");
            scanf("%d",&new -> data);
            new -> next = ptr -> next;
            ptr -> next = new;
        }
        ptr = ptr -> next;
    }
    if( flag == 0)
        printf("\nSearch data not found\n");
    if( flag == 1)
        printf("\nNew node inserted\n");    
}


void deletefront()
{
  if( head == NULL) 
    {
        printf("\nLinked list empty\n");
        return;
    } 
   else
   {
            ptr = head -> next;
            head -> next = NULL; 
            free(head);
            if(ptr == NULL)
                head = NULL;
            else
                head = ptr; 
            printf("\nNode deleted\n");
   }   
}

void deleteback()
{
    if( head == NULL) 
    {
        printf("\nLinked list empty\n");
        return;
    } 
   else
   {
       ptr = head;
       new = ptr;
        while(ptr -> next != NULL)
        {
            new = ptr;
            ptr = ptr -> next;
        }
        if(new -> next == NULL)
            head = NULL;
        new -> next = NULL;
        ptr -> next = NULL;
        free(ptr); 
        printf("\nNode deleted\n");
   }   
}

void deletespecific()
{
    if( head == NULL) 
    {
        printf("\nLinked list empty\n");
        return;
    } 
   else
   {
        int search,flag=0;
        ptr =  head;
        new = head;
        printf("\nEnter search data:\n");
        scanf("%d",&search);
        while(ptr != NULL)
        {
            if( ptr -> data == search)
            {
                flag = 1;
                printf("Deleting data: %d",ptr -> data);
                if(ptr -> next == NULL && ptr == new)
                    {
                        head = NULL;
                      //printf("executing1");
                        goto tagme;
                    }
                if(ptr == new)
                {
                    head = head -> next;
                    //printf("executing2");

                }
                new -> next = ptr -> next; 
                ptr -> next = NULL;
                tagme:
                free(ptr);
                //printf("executing3");
                break;
            }
            new = ptr;
            ptr = ptr -> next;
        }
        if( flag == 0)
            printf("\nSearch data not found\n");
        if( flag == 1)
            printf("\nNode deleted\n");      
    }  
}

void display()
{   
    {   
        if( head == NULL) 
        {
            printf("\nLinked list empty\n");
            return;
        } 
    else
        {
            ptr=head;
            printf("\n\nDisplaying:\n\n");
            while(ptr->next!=NULL)
                {
                    printf("  %d ->",ptr->data);
                    ptr = ptr->next;        
                }      
            printf(" %d",ptr->data);  
            
        }
    }      
}

void main()
{
    int opt;
    
    do
    {
        printf("\n\n____________________________________\n");
        printf("\n\t\tMENU\n");
        printf("\n1.Insertion[FRONT]\n2.Insertion[BACK]\n3.Insertion[SPECIFIC]\
        \n4.Deletion[FRONT]\n5.Deletion[BACK]\n6.Deletion[SPECIFIC]\
        \n7.Display\n8.Exit\n\nEnter your option: \n");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1:
                insertfront();
                break;
            case 2:
                 insertback();
                 break;
            case 3:
                insertspecific();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                deleteback();
                break;
            case 6:
                deletespecific();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid option\n");
        }

    }while(1);
}