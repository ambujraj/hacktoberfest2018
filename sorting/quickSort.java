/* QuickSort.java - Perform a quicksort on an array of doubles
 * Author:     Textbook
 * Module:     8
 * Project:    Demonstration
 * Description: Class that realizes the divide-and-conquer sorting pattern and
 *     uses the quicksort algorithm.
 *
 *    Instance Variables
 *       (none)
 *
 *    Methods:
 *       sort - performs a recursive sort using quicksort algorithm
 *       split - writes everything below a splitValue (which in this case
 *               is the first element being "sorted", then the splitValue itself,
 *               then everything greater than the splitValue
 *       join - does nothing in the quick sort algorithm
 */

public class QuickSort {

    public static void sort(double[] a, int begin, int end)//begin is the first indice and end is the last
    {

        // If sorting more than one element, then perform a sort, otherwise
        // do nothing because single element array is by default already sorted
        if ((end - begin) >= 1)
        {

           /*******************************************************************
            * For a quick sort, this is the method that does all the work.  It
            * takes the element at index 'begin' as the splitValue, and uses it
            * to sort all of the
            * elements from begin to end into those less than the split point,
            * the split point itself, and those elements greater than the
            * split point
            ********************************************************************/
            int splitPoint = split(a, begin, end);

           /********************************************************************
            * The first sort now sorts everything above the splitValue calculated
            * above in splitPoint (which we know is less than the original
            * element at a[begin]), and those less than the splitValue from
            * above.
            ********************************************************************/
            sort(a, begin, splitPoint) ;
            sort(a, splitPoint + 1, end) ;

            // In a quick sort, the join method does nothing
            join(a, begin, splitPoint, end)  ;
        }
    }

    // In a quick sort, this method does all the work
    private static int split(double[] a, int begin, int end) {

        // Create a new temporary array to store the elements divided into
        // those less than the split point (the first element), the split
        // point, and those elements greater than the split point
        double[] temp;
        int size = (end - begin + 1);
        temp = new double[size];

        // Use the first element in the array being sorted as the split value
        double splitValue = a[begin];
        int up = 0;
        int down = size - 1;

        // Note that a[begin] = splitValue is skipped -- the starting value
        // If the next element in the array is less than splitValue, then add
        // to the front of the new array, otherwise add to the back of the
        // new array
        for (int i = begin + 1; i <= end; i++)
        {
            if (a[i] < splitValue)
            {           // changed from version in book!!!!
                temp[up++] = a[i];
            }
            else
            {
                temp[down--] = a[i];
            }
        }

        // 0 <= up = down < size

        // Last thing to do is add the splitValue itself into the array
        // of elements in temp
        temp[up] = a[begin];

        // Copy the temporary array back into the original array
        for (int i = 0; i < size; i++)
            a[begin + i] = temp[i];

        // As a result, we have written elements less than the splitValue element,
        // then the splitValue element, then those elements greater than the
        // splitValue element:
        //      temp[i] <= splitValue for i < up
        //      temp[up] = splitValue
        //      temp[i] > splitValue for i > up
        return (begin + up);
    }

    private static void join(double[] a, int begin, int splitPoint, int end)
    {
        //Nothing to do.
    }
}
