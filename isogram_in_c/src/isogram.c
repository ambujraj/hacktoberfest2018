#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "isogram.h"

bool is_isogram(const char phrase[]) 
{
   int index = 0;
   if (phrase == NULL)
   {
    return false;
   }
   index = strlen(phrase);
   bool result = true;

   for (int i=0; i < index; i++)
   {
       for (int j=i+1; j < index; j++)
       {
           if (is_printable(phrase[i]) && is_printable(phrase[j]))
           {
               char temp1, temp2;
               temp1 = capitalize(phrase[i]);
               temp2 = capitalize(phrase[j]);
               //printf("temp1 = %c, temp2 = %c \n", temp1, temp2);
               if (temp1 == temp2)
                   result = false;
           }
       }
   }

   return result;
}

bool is_printable(const char x)
{
    bool result = false;
    if ((x > 0x40 && x < 0x5B) || (x > 0x60 && x < 0x7B))
        result = true;
    return result;
}

char capitalize(const char x)
{
    char ret;
    if ( x > 0x60 && x < 0x7B )
        ret = x - 32;
    else 
        ret = x;
    return ret;
}
