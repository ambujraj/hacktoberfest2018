import java.util.Scanner;

public class GearsOfWar {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		int q = in.nextInt();
		
		if (q >= 1 && q <= 100000) {
			int[] gears = new int[q];
			
			for (int n = 0; n < gears.length; n++) {
				gears[n] = in.nextInt();
			}
			
			for (int n = 0; n < gears.length; n++) {
				if (gears[n] >= 3 && gears[n] <= 100000) {					
					if (gears[n] % 2 == 0) {
						System.out.println("Yes");
					} else {
						System.out.println("No");
					}
				}
			}			
		}
		
		in.close();

	}

}