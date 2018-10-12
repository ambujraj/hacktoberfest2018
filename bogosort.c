/*
 * Bogosort (or "Estou com Sort (pt-BR)", kinda like "I'm feeling lucky"): Probably the worst sorting 
 * algorithm out there.
 *
 * This implementation is based on Rosetta Code's implementation.
 * see: https://rosettacode.org/wiki/Sorting_algorithms/Bogosort#C
 *
 * Additions and changes by Rafael Julio (11/10/2018):
 * - Renamed variables and functions.
 * - Comments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Verifies if a given number is already sorted.
bool isSorted(int *array, int number)
{
    while ( --number >= 1 ) {
        /* 
         * While (number -1) is greater than 1, and IF this number is lesser
         * than (itself -1), this number isn't sorted.
         */
        if (array[number] < array[number-1]) {
            return false
        }
    }
  
    return true;
}
 
void shuffle(int *array, int number)
{
    // Randomly shuffles a number into the array.
    int i, t, r;
  
    for(i = 0; i < number; i++) {
        t = a[i];
        r = rand() % number;
        a[i] = a[r];
        a[r] = t;
    }
}
 
void bogosort(int *array, int number)
{
    /*
     * If an array of number isn't sorted, shuffles them in hope of sorting
     * out everything.
     */
    while (!is_sorted(a, number)) {
        shuffle(a, number);
    }
}
 
int main()
{
    int numberArray[] = { 1, 10, 9, 7, 3, 0 };

    // bogosort(); expects the array and it's size as arguments.
    bogosort(numberArray, 6);
    
    // When (if) everything is sorted, print's out every number in the array.
    for (int i = 0; i < 6; i++) {
        printf("%d ", numberArray[i]);
    }
    
    // End everything with a beautiful \n character.
    printf("\n");
    
    return 0;
}