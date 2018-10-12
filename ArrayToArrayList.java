import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
class A{
  public static void main(String args[])
    { int[] arr={1,5,6,7,42,4,};
	  System.out.println(Arrays.toString(arr));
	  //Create Integer array bcz in List Integer works not int
	  Integer[] i=new Integer[arr.length];
	 //Put arr element into Integer array
	 for(int j=0;j<arr.length;j++)
	  { i[j]=Integer.valueOf(arr[j]);
		  
	  }
	  //Convert List into arrayList
 	 ArrayList<Integer> ar=new ArrayList<>(Arrays.asList(i));
	 ar.add(54889);
	   System.out.println(ar);
     
    	   
	  
	}

}
