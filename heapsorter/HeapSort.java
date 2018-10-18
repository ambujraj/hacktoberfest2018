package heapsorter;

public class HeapSort
{
    public void sort(int arr[])
    {
        int unsortedArray = arr.length;

        for (int i = unsortedArray / 2 - 1; i >= 0; i--)
            heapify(arr, unsortedArray, i);

        for (int i = unsortedArray-1; i >= 0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }

    static void printArray(int arr[])
    {
        int unsortedArray = arr.length;
        for (int i = 0; i < unsortedArray; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String args[])
    {
        int arr[] = {12, 15, 13, 5, 14, 11, 6, 7, 1, 8, 4};

        HeapSort ob = new HeapSort();
        ob.sort(arr);

        System.out.println("The array got heap sorted:");
        printArray(arr);
    }
}
