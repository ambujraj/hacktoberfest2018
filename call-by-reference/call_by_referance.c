#include <stdio.h>
void increment(int  *var)
{
    *var = *var+1;
}
int main()
{
     float num;
     scanf("%lf",&num);	
     increment(&num);
     printf("Value of num is: %d", num);
   return 0;
}
