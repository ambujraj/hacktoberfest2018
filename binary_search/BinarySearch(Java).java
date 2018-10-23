public class BinarySearch 
{  
	public static int bsearch(int arr[], int numb)
{
     int l = 0, r = arr.length - 1;
      while(l <= r)
{  
      int mid = (l + r) >> 1;  
      if (arr[mid] == numb)
{  
        return mid;  
      } 
else if(arr[mid] < numb)
{  
        l = mid + 1;     
}
	else
{  
         r = mid - 1;  
}
}
   return -1;
}
 public static void main(String args[])
{  
    int arr[] = {100,200,300,400,500};  
    int numb = 100;  
    int ans = bsearch(arr,val);
    System.out.println((ans == -1) ? "Element not found" : "Element is found at index: " + ans);  
 }
}
