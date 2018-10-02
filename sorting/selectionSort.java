class SelectionSort{
//Selection Sort
	public static int[] selectionSort(int A[]) {
		int i;
		int j;
		int chosen;
		int minor;
		int pos;
		long exchanges = 0;
		long comparisons = 0;
		
		for(i = 0;i<A.length-1;i++) {
			comparisons++;
			chosen = A[i];
			minor = A[i+1];
			pos = i+1;
			exchanges += 3;
			for(j = i+2;j<A.length;j++) {
				comparisons++;
				if(A[j]<minor) {
					comparisons++;
					minor = A[j];
					pos = j;
					exchanges =+ 2;
							
				}
			}
			
			if(minor<chosen) {
				comparisons++;
				A[i] = A[pos];
				A[pos] = chosen;
				exchanges += 2;
				
			}
		}
		System.out.println("Exchanges: "+exchanges+" Comparisons: "+comparisons);
		return A;
	}
}
