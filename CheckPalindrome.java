import java.util.Scanner;
class CheckPalindrome {
	public static void main (String args[]) {
		System.out.print ("Enter a number: ");
		int a = new Scanner(System.in).nextInt();
		
		if (checkPalindrome(a))
			System.out.println("It is a palindrome!");
		else
			System.out.println("It is not a palindrome.");
	}
	
	private static boolean checkPalindrome(int n) {
		String r = "";
		String num = Integer.toString(n);
		
		for (int i = num.length() - 1; i >= 0; i--) {
			r += num.charAt(i);
		}
		
		if (r.equals(num))
			return true;
		else
			return false;
	}
}
