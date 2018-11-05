import java.util.Scanner;

public class CountSort {

	static void countSort(char arr[])
	{
		int n = arr.length;
		char output[] = new char[n]; 
		
		int count[] = new int[256]; 
		
		for (int i=0; i<256; ++i) 
            count[i] = 0; 
		
		for (int i=0; i<n; ++i) 
            ++count[arr[i]]; 
		
		for (int i=1; i<=255; ++i) 
            count[i] += count[i-1]; 
		
		
		for (int i = n-1; i>=0; i--) 
        { 
            output[count[arr[i]]-1] = arr[i]; 
            --count[arr[i]]; 
        } 
		
		
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
