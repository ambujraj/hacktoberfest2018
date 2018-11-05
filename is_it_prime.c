#include <stdio.h>
#include <math.h>

int main()
{
  int a,i,k=0;
  scanf("%d",&a);
  if( a < 0 )
    printf("it is negative");
  else if( a % 2 == 0 || a == 1 )
    printf("it is not prime");
  else
  {
    for( i = 3 ; i <= sqrt(a) ; i += 2 )
      if( a % i == 0 )
      {
        k = 1;
        break;
      }
    if( k )
      printf("it is not prime");
    else
      printf("it is prime");
   }
}
