#include <stdio.h>
int main()
{
   char hello[13]="Halo, Dunia!";

   for (int i = 0; i < 14; ++i)
   {
   	printf("%c", hello[i]);
   }
   printf("\n");
   return 0;
}
