#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
  
int main() 
{ 
   srand(time(NULL)); 
   int i; 
  
   for(i = 0; i<5; i++) 
  printf("%d\t", rand()%10); 
} 