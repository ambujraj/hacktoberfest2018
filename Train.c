	#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
typedef struct node
{
  int seat;
  char name[15];
  int age;
  char gender;
  char time[40];
  struct node* next;
}list,*ptr;

void delet(ptr a);
void add(ptr a);
void printseat(ptr temp);
void print(ptr a);
int main()
{
  int i,input;
  ptr a;
  a=(ptr)malloc(1*sizeof(list));
  a->next=NULL;
  a->seat=0;

  for(i=0;i<100;i++)
    {
	  printf("\t\t\t***********************\n");
	  printf("\t\t\t\tWELCOME\n");
	  printf("\t\t\t***********************\n");
      printf("ENTER\n 1 To book a ticket\n 2 For deleting a ticket\n 3 To print the chart\n 4 To exit the application \n");
      scanf("%d",&input);
      system("cls");
      
      if(input==1)
 	{
   		add(a);
 	}
      else if(input==2)
 	{
  	 	delet(a);
 	}
      else if(input==3)
 	{
  		print(a);
 	}
      else if(input==4)
 	{
   		break;
 	}
      else
 	{
   		printf("Not able to recognise the command \n");
 	}
    }
  printf("Thank you \n");
  return 0;
}
void add(ptr a)
{
  system("cls");
  int input,input2;
  ptr temp=NULL;
  while(a->next!=NULL)
    {
      a=a->next;
    }
  if(a->seat>72)
    {
      printf("Train is full \n");
      return ;
    }

  temp=(ptr)malloc(1*sizeof(list));
  temp->next=NULL;
  printf("Enter name =");
  scanf("%s",temp->name);
  printf("Enter age =");
  scanf("%d",&temp->age);
  printf("Enter gender =");
  scanf("%s",&temp->gender);
  temp->seat=(a->seat)+1;
  system("cls");
  printf("You have successfully book ticket\n");
  printf("Enter\n 1 To print the ticket\n 2 For exit the booking\n");
  scanf("%d",&input);
  if(input==1)
    {
      printseat(temp);
    }

  a->next=temp;
  return ;
}
void printseat(ptr temp)
{
	system("cls");
  printf("Confirm seat=%d\n",temp->seat);
  printf("Name=%s\n",temp->name);
  printf("Gender=%c\n",temp->gender);
  printf("Age=%d\n\n",temp->age);
  return ;
}
void print(ptr a)
{
	system("cls");
	 time_t t;
 	 t=time(NULL);
  a=a->next;
  while(a!=NULL)
    {
	  printf("\t\t\t*******************************\n");
	  printf("\t\t\tTicket information\n");
	  printf("\t\t\t*******************************\n");
      printf("\t\t\tSeat number=%d\n\t\t\tName=%s\n\t\t\tAge=%d\n\t\t\tGender=%c\n",a->seat,a->name,a->age,a->gender);
      printf("\t\t\tTiming=%s\n",ctime(&t));
      a=a->next;
    }
  return ;
}
void delet(ptr a)
{
  int input;
  ptr temp;
  a=a->next;
  printf("Enter the seat number \n");
  scanf("%d",&input);
  while(a!=NULL&&(a->seat)!=input)
    {
      a=a->next;
    }
  if(a==NULL)
    {
      printf("The seat is already empty\n");
      return ;
    }
  temp=a;
  a=a->next;
  free(temp);
  while(a!=NULL)
    {
      a->seat=a->seat-1;
      a=a->next;
    }
  printf("Seat deleted \n");
  return ;
}

