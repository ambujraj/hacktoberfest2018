#include<stdio.h>
#include<conio.h>
#define max 5
void push(int stack[], int val);
int pop(int stack[]);
int peep(int stack[]);
void display(int stack[]);
int stack[max];
int top = -1;
int main(){
int val, option;
clrscr();
do{
printf("\n 1.PUSH");
printf("\n 2.POP");
printf("\n 3.PEEP");
printf("\n 4.display");
printf("\n\nenter your choice :");
scanf("%d", &option);
switch(option){
case 1: printf("enter the value to be pushed");
        scanf("%d", &val);
		push(int stack, int val);
		break;
case 2: val= pop(stack);
        printf("the value poped is: %d", val);
		break;
case 3: val=peep(stack);
        printf("the top of the stack is: %d", val);
		break;
case 4: display(stack);
        break;
}} while(option != 5);
return 0;
}
void push(int stack[], int val){
	if(top == max-1){
		printf("stack is full");
	}
	else{
		top++;
		stack[top] = val;
	}
}
int pop(int stack[]){
	int val;
	if(top == -1){
		printf("stack is underflow");
		return -1;
	}
	else{
		val= stack[top];
		top--;
		return val;
	}
}
int peep(int stack[]){
	int val;
	if(top== -1){
		printf("stack is underflow");
		return -1;
	}
	else{
		val =stack[top];
		return val;
	}
}
void display(int stack[]){
	int i;
	if(top == -1){
		printf("stack is underflow");
	}
	else{
		for(i=top; i>=0; i--){
			printf("the stack elements are: %d", stack[i]);
		}
	}
}
