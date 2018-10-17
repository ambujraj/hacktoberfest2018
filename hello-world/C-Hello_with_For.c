#include <stdio.h>
int main()
{
   char hello[13]="Hello World!";

   for (int i = 0; i < 14; ++i)
   {
   	printf("%c", hello[i]);
   }
   printf("\n");
}
