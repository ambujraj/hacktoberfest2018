#include<stdio.h>
#include<stdlib.h>

int hashkey(int tmp);
int probe(int tmp, int x);
int a[10];
int main(void)
{
    int tmp = 0,i;
    for(i=0;i<10;i++)
    {
        a[i] = -1;
    }
    for(i=0;i<10;i++)
    {
        printf("Enter the element you want : ");
        scanf("%i",&tmp);
        hashkey(tmp);
    }
    for(i=0;i<10;i++)
    {
        printf("The data in %i is : %i \n ",i,a[i]);
    }
    return 0;
}

int hashkey(int tmp)
{
    int x=0,count=0,i=0,b = tmp;
    x = (tmp % 10 + 0) % 10;
    if(a[x] != -1)
    {
        count++;
        probe(b,x);
    }
    else
    {
        a[x] = b;
    }
}

int probe(int tmp, int x)
{
    int i= 0,j = 1,c = tmp;
    while ( a[x] != -1)
    {
        j++;
        x = (tmp % 10 + j ) % 10;
    }
    a[x] = c;
}
