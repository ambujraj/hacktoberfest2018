#include <stdio.h>
 
int main()
{
  int array[100], search, count, num;
 
  printf("Enter number of elements in array\n");
  scanf("%d", &num);
 
  printf("Enter %d integer(s)\n", num);
 
  for (count = 0; count < num; count++)
    scanf("%d", &array[count]);
 
  printf("Enter a number to search\n");
  scanf("%d", &search);
 
  for (count = 0; count < num; count++)
  {
    if (array[count] == search) 
    {
      printf("%d is present at location %d.\n", search, count+1);
      break;
    }
  }
  if (count == num)
    printf("%d isn't present in the array.\n", search);
 
  return 0;
}