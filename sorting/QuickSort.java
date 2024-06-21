class QuickSort{
  //Quick Sort
  //To call, use QuickSort.quickSort(arr, 0, arr.length-1);
	public static int quickSort(int A[], int start, int end)
    {
        int pivot = A[end]; 
        int i = (start-1); 
        int exchanges = 0;
		int comparisons = 0;
		
        for (int j=start; j<end; j++){
        	comparisons++;
           
            if (A[j] <= pivot){
            	comparisons++;
              i++;
              int temp = A[i];
              A[i] = A[j];
              A[j] = temp;
              exchanges += 3;
            }
        }

        int temp = A[i+1];
        A[i+1] = A[end];
        A[end] = temp;
        exchanges += 3;
        
        System.out.println("Exchanges: "+exchanges+" Comparisons: "+comparisons);
        return i+1;
    }
	
 	//Main quickSort function
    public static void quickSortMain(int A[], int start, int end){
    	
        if (start < end){
        	
            int pi = quickSort(A, start, end);

            quickSortMain(A, start, pi-1);
            quickSortMain(A, pi+1, end);
        }
    }

}
