import java.util.*;

class BinarySearch<E extends Comparable<E>> {
    E[] array;

    public BinarySearch(E[] array) {
        this.array = array;
    }
    public void findRecursive(E value) {
        int index = binarySearchRecursive(value, -1, 0, array.length - 1);

        System.out.println( 
            (index > -1) 
            ? "Value '" + value + "' was found recursively at index: " + index
            : "Value '" + value + "' was not found recursively in the dataset: " + Arrays.asList(array)
        );
    }
    private int binarySearchRecursive(E value, int index, int left, int right) {

        if(left <= right) {
            int midIndex = left + ((right - left) / 2);
            if(value.equals(array[midIndex])) {
                index = midIndex;
            }
            else { 
                if(value.compareTo(array[midIndex]) < 0) {
                    right = midIndex - 1;
                }
                else {
                    left = midIndex + 1;
                }

                index = binarySearchRecursive(value, index, left, right);
            }
        }

        return index;
    }
    
    public void search(E value) {
        findRecursive(value);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Integer[] ints = new Integer[n];
        for(int i = 0; i < n; i++) {
            ints[i] = i;
        }
        BinarySearch<Integer> intSearch = new BinarySearch<Integer>(ints);
        while(scanner.hasNext()) {
            int value = scanner.nextInt();
            intSearch.search(value);
            System.out.println();
        }
        scanner.close();
}
}
