import java.util.Scanner;
//Counting sort is a sorting technique based on keys between a specific range
public class CountingSort {

	static void countSort(char arr[])
	{
		int n = arr.length;
		char output[] = new char[n]; 
		//Creating the count array for each charecters
		int count[] = new int[256]; 
		//initializing count array
		for (int i=0; i<256; ++i) 
            count[i] = 0; 
		//incrementing the occurences of charecters in the array
		for (int i=0; i<n; ++i) 
            ++count[arr[i]]; 
		//updating the count array to hold correct position of each charecters
		for (int i=1; i<=255; ++i) 
            count[i] += count[i-1]; 
		
		//building the output array
		for (int i = n-1; i>=0; i--) 
        { 
            output[count[arr[i]]-1] = arr[i]; 
            --count[arr[i]]; 
        } 
		
		//coping the result to original array
		for (int i = 0; i<n; ++i) 
            arr[i] = output[i]; 
	}
	
	public static void main(String...args)
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the string you want to sort");
		String str=s.nextLine();
		char arr[]=str.toCharArray();
		countSort(arr);
		System.out.println("Result:"+new String(arr));
	}
}
