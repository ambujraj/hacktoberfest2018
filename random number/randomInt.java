import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		System.out.println("RANDOM INTEGER GENERATOR:");
		//Get Input
		System.out.print("Enter min value: ");
		Scanner s = new Scanner(System.in);
		double min = s.nextDouble();
		System.out.print("Enter max value: ");
		double max = s.nextDouble();
		
		//DecimalFormat to get rid of trailing '.0'
		DecimalFormat format = new DecimalFormat("0");
		System.out.println("Random number: "+format.format(getRandInt(min,max)));

	}
	public static double getRandInt(double min, double max) {
		double num = (int)(Math.random()*((max-min)+1))+min;
		return num;
	}

}
