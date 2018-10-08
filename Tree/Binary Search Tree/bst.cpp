#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct bstnode{
	
	int data;
	struct bstnode*left;
    struct bstnode*right;
	
};

bstnode*root=NULL,*temp;

 
 #define count 10
 
void display(bstnode *,int );
void insertion();
void rootdisp(bstnode *) ;




int main()
{
	
	int ch,ch1;
	ch=1;
	
	
	while(ch)
{
	printf("ENTER THE CHOICE FROM THE MENU \n 1.INSERTION \n 2.DISPLAY\n 3.EXIT\n");
	scanf("%d",&ch1);
	   	
	   switch(ch1)	
		{
			
			case 1 : insertion();
			         break;
			         
			case 2 : rootdisp(root);
					
			         break;
					 
		    case 3 : exit(0); 			         
			
		}
		
}
	
return 0;	
	
}



void insertion()
{
	int ch;
	ch=1;
	
    bstnode*parent;
	parent=root;
		
	
	while(ch==1)
	{
			
		temp= (bstnode*)malloc(sizeof(bstnode));
		
		printf(" enter the data \t");
		scanf("%d",&temp->data);
		
		temp->left=NULL;
		temp->right=NULL;
		
		
		
		
		if(root==NULL)
		{
			root=temp;
		}
		
		else
		{   
		    bstnode*curr;
		    curr=root;
		    
			while(curr)
			{
			    parent=curr;	
			
				if(temp->data>curr->data)
				{
				
			    	curr=curr->left;
				}
			
				else
				{
				
			    	curr=curr->right;	
				}
			
		   }
   
       		if(temp->data>parent->data)
       		{
       			parent->left=temp;
       	   
	   		}
	   		else
	   		{
	   	
	   			parent->right=temp;
	   		}
   
   
   
        }
   
        printf(" want to enter more(0/1)");
        scanf("%d",&ch);
    
    }

}
void display(bstnode *root,int space)
{ 

    if (root == NULL) 
        return; 
  
   
    space += count; 
  
    display(root->right, space); 
  
    
    printf("\n"); 
    
	for (int i =count; i < space ; i++) 
       printf(" "); 
	    
    printf("%d\n", root->data); 
  
    
    display(root->left, space); 
} 
  
 
void rootdisp(bstnode *root) 
{ 
    
   display(root, 0); 
} 
