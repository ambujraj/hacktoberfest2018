import java.util.Scanner;

public class Fibonacci{

  public static void main(String[] args){
   
    Scanner scan = new Scanner(System.in);
    int num = 0;
    
    System.out.println("How many fibonacci numbers would you like?");
    try{
      num = scan.nextInt();
    }catch(Exception e){
      System.out.println("Error: please enter a positive integer.");
    }
    
    scan.close();
    int previousNum = 0;
    int currentNum = 1;
    int temp = 0;
    
    for(int i = 1; i <= num; i++){
      System.out.print(currentNum + " ");
      temp = currentNum;
      currentNum += previousNum;
      previousNum = temp;
    }
    
  }

}
