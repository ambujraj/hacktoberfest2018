import java.io.*;
import java.math.*;
public class Square {
	public static void main(String[] args) {

		System.out.println("Enter a number which is to be checked for being a square:");

		Console console = System.console();
		try {

			int number = Integer.valueOf(console.readLine());

			double answer = Math.sqrt(number);

			if((int) answer == answer) {
				System.out.println("Number: " + number + " is a perfect square!");
			} else {
				System.out.println("Number: " + number + " isn't a perfect root!");
			}
		} catch(NumberFormatException e) {
			System.out.println("Bad number! Please check your input.");
			System.exit(-1);
		}
	}

}