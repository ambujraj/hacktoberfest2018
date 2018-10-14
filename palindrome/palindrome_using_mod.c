#include<stdio.h>
void main(){
	int num,rev=0,cpy;
	scanf("%d",&num);
	cpy=num;
	while(num){
		rev = (rev*10) + (num%10);
		num /=10;
	}
	if(cpy == rev) printf("Palindrome\n");
	else printf("Not Palindrome\n");
}