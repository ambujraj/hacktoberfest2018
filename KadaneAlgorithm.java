
public class KadaneAlgorithm {

	public static void main(String[] args) {
		int max = kadane(new int[] { 1, 2, -4, 3, 6, -10, 8, 7 });
		System.out.println(max);
	}

	public static int kadane(int[] arr) {
		int localMax = arr[0];
		int gloMax = arr[0];
		for (int i = 1; i < arr.length; i++) {
			localMax = Math.max(arr[i], localMax + arr[i]);
			gloMax = Math.max(localMax, gloMax);
		}
		return gloMax;
	}

}
