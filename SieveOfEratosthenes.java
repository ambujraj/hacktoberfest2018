
public class SieveOfEratosthenes {

 	public static void main(String[] args) {
		sieveOfEratosthenes(100);
	}
  
 	public static void sieveOfEratosthenes(int n) {
		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i < n; i++)
			prime[i] = true;
 		for (int p = 2; p * p <= n; p++) {
			if (prime[p] == true) {
				for (int i = p * 2; i <= n; i += p)
					prime[i] = false;
			}
		}
 		for (int i = 2; i <= n; i++) {
			if (prime[i] == true)
				System.out.print(i + " ");
		}
	}
  
 }
