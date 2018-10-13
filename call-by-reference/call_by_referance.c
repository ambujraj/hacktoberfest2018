#include <stdio.h>

void increment(int  *num)
{
    *num = *num+1;
}
int main()
{
     int num=20;
     increment(&num);
     printf("Value of num is: %d", num);
   return 0;
}
