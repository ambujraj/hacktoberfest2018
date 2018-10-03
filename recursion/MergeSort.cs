namespace Merge_Sort
{
    public class MergeSort
    {
        public static void SortBy(int[] array, int leftBorder, int rightBorder)
        {
            if (leftBorder >= rightBorder)
                return;
            int middle = (leftBorder + rightBorder) / 2;
            SortBy(array, leftBorder, middle);
            SortBy(array, middle+1, rightBorder);

            int[] buf = new int[rightBorder-leftBorder+1];

            int i = leftBorder;         //index of left array
            int j = middle + 1;         //index of right array
            int k = 0;                  //index of final array
            while (i <= middle && j <= rightBorder)
            {
                if (array[i] < array[j])
                    buf[k++] = array[i++];
                else
                    buf[k++] = array[j++];
            }
            //Add the tail of right array
            while (j <= rightBorder)   
                buf[k++] = array[j++];
            //Add the tail of left array
            while (i <= middle)  
                buf[k++] = array[i++];

            for (k = 0; k < rightBorder - leftBorder + 1; k++)
                array[leftBorder + k] = buf[k];
        }
    }
}
