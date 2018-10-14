public class IterativeBinarySearch {
    public static boolean binarySearchIterative(int [] arr, int elem){
        int lo = 0;
        int hi = arr.length - 1;
        int mid;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(elem < arr[mid]) {
                hi = mid - 1;
            }else if(elem > arr[mid]) {
                lo = mid + 1;
            }else {
                return true;
            }
        }
        return false;
    }

    public static void main(String [] args) {
        int [] arr = {1,2,3,4,5,6,7,8,9,10};
        System.out.println("Binary Search Iterative - Found?");
        System.out.println(binarySearchIterative(arr, 4));
    }
}