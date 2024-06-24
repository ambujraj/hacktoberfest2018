/* This is a simple Java program.*/
public class HelloWorld {
 // Your program begins with a call to main(). 
    // Prints "Hello, World" to the terminal window. 
    public static void main(String[] args) {

         System.out.println("Hello World!");
         String s;
         Scanner obj = new Scanner(System.in); /* create a object */ 
         System.out.println("Enter your name:");
         s = obj.nextLine(); /* Take string input and assign to variable */      
         System.out.println("You entered string "+s); /* Print */ 
        
    }
    
}
