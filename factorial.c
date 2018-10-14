#include <stdio.h>
int main(){
    int num;
    int i;
    int factorial=1;
    printf("Enter the number: ");
    scanf("%d",&num);
    for (i = 1; i <= num; i++){
        factorial=factorial*i;
    }
    printf("Factorial of %d is %d",num,factorial);
    return 0;
    }
