#include <stdio.h>

/* fold: breaks long lines of input into two or more lines at blank-space characters
 * after the n-th column of input */

main()
{
    int c;
    int column = 0;

    while ((c = getchar()) != EOF){
        if ((c == ' ' || c == '\t') && column >= 9){
            putchar('\n');
            c = 0;
            column = 0;
        }
        putchar(c);
        ++column;
    }
}
