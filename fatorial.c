#include <stdio.h>

int main(){
    int num;
    int i;
    int fatorial=1;
    printf("Digite um número inteiro para calcular o fatorial dele: ");
    scanf("%d",&num);
    for (i = 1; i <= num; i++){
        fatorial*=*i;
    }
    printf("\nO fatorial de %d é %d\n",num,fatorial);
    return 0;
}
