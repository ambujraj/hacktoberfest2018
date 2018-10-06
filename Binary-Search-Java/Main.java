import java.util.*;

public class Main {

	public static int binarySearch(int[] arr,int start, int end, int num){
    	//Number not found
        if(start>end)
            return -1;

        int mid = (start+end)/2;

        //Final result
        if(arr[mid]==num)
            return mid;
        else if(num>arr[mid])  //Search right side of the mid
            return binarySearch(arr,mid+1,end,num);
        //Search left side of mid
        else return binarySearch(arr,start,mid-1,num);
    }

    
    public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
    	//Take no. of elements as input
    	int n = input.nextInt();

    	/*Take numbers as input into array arr in ascending order
    	Since Binary Search only applies to sorted array. 
    	*/

    	int[] arr = new int[n];
        for(int i=0;i<n;i++)
        	arr[i]=input.nextInt();

        //Take input of number to be searched
        int number=input.nextInt();

        //Perform binary search
        int index=binarySearch(arr,0,arr.length-1,number);
        
        if(index==-1)
            System.out.println("Number not found");
        else System.out.println("Numebr found at index "+index);
    }

    
}


/*

Sample Case 1-

Input -

8
5 10 15 17 24 29 35 40
15

Output-
Number found at index 2

Sample Case 2- 

Input - 
5
1 3 7 9 15
25

Output-
Number not found


*/
