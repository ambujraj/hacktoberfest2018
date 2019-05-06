public class RecursiveBinarySearch {
    public static void binarySearch(int [] arr, int elem) {
        binarySearch(arr, 0, arr.length - 1, elem);
    }
  
    public static void binarySearch(int [] arr, int lo, int hi, int elem) {
        int mid = lo + (hi - lo) / 2;
        System.out.println("hi: "+hi+" - lo: "+lo+" - mid: " + mid);
        System.out.println("arr[mid]: " + arr[mid]);
        System.out.println("elem: " + elem);
        
        if(elem == arr[mid]){
            System.out.println("arr[mid] == elem ? " + (arr[mid] == elem));
        }else if(elem < arr[mid]) {
            binarySearch(arr, lo, mid - 1, elem);
        }else if(elem > arr[mid]) {
            binarySearch(arr, mid + 1, hi, elem);
        }else {
            System.out.println("arr[mid] == elem ? false");
        }
    }

    public static void main(String [] args) {
        int [] arr = {1,2,3,4,5,6,7,8,9,10};
        System.out.println("Binary Search Recursive");
        binarySearch(arr, 4);
    }
}