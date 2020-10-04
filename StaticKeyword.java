package oops;

import oops.A.B;
import oops.A.C;

public class StaticKeyword {
	
	static {
		System.out.println("Block 1");           // methods of static
	}
	
	static {
		System.out.println("Block 2");
	}
	

	public static  void main(String[] args) {
		
		
		
	
		
		A objA = new A(); 
		
		B objB =  objA.new B(); //Creating a nested non static class object needs that the object of parent class should be created first.
		
		C objC = new A.C(); // Creating a static class object is simple as well.
		
		System.out.println("In  Main");

	}
	
	static {
		System.out.println("Block 3");  // Static block code runs before the main method. If we need any piece of code to executed before the main, static blocks are the choice.
	}

}
