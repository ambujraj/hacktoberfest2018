#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include "acronym.h"

char *abbreviate(const char *phrase)
{
    size_t count = 0;


    if (phrase == NULL) return NULL;
    size_t length = strlen(phrase);
    if (length == 0) return NULL;

    char * abbrev =  malloc(sizeof(size_t)*14);

    abbrev[0] = toupper(phrase[0]);
    
    for ( const char * ptr = phrase; *ptr; ptr++)
    {
        if (*ptr == 32 || *ptr == 45) 
        {
            count ++;
            abbrev[count] = toupper(*(ptr + 1)); 
        }
    }

    abbrev[count + 1] = '\0';
    return abbrev;
}
