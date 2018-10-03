// HeapSorted Implementation (based on CLRS Introduction to Algoithms).

using System;

namespace HeapSort {
    class Program {

    static void MaxHeapify(int[] A, int low, int i, int HeapSize)
    {
    	int largest;
    	int l = 2*(i)+1; //LEFT(i)
    	int r = 2*(i)+ 1 + 1; // RIGHT(i)
    	if (l< HeapSize  && A[low+l]>A[low+i])
    	{
    		largest = low+l;
    	}
    	else largest = low+i;
    	if (r< HeapSize && A[low+r]>A[largest])
    	{
    		largest = low+r;
    	}
    	if (largest != (low+i))
    	{
    		int temp = A[i+low];
    		A[i+low] = A[largest];
    		A[largest] = temp;
    		MaxHeapify(A, low, largest-low, HeapSize );
    	}
    }

    static void BuildMaxHeap(int[] A, int low, int high, int HeapSize)
    {
    	for (int i=(high-low+1)/2-1; i>=0; i--)
    	{
    		MaxHeapify(A,low, i, HeapSize);
    	}
    }

    static void heapSort(int[] A, int low, int high)
    {
    	int HeapSize = high-low+1;
    	BuildMaxHeap(A, low, high, HeapSize);
    	for (int i=high; i>low; i--)
    	{
    		int temp = A[i];
    		A[i] = A[low];
    		A[low] = temp;
    		HeapSize--;
    		MaxHeapify(A,low, 0, HeapSize);
    	}
    }

    static void Main()
    {
        int[] A = {9,4,5,6,5,3,2,10,200,1}; // Random test data
        Console.Write("UNSORTED:\n");
        for(int i=0; i<A.Length; i++) Console.Write(A[i]+" ");
        Console.Write("\n");    
        heapSort(A, 0, A.Length-1);
        Console.Write("SORTED:\n");
        for(int i=0; i<A.Length; i++) Console.Write(A[i]+" ");
        Console.Write("\n");     
    }

    

    }
}



