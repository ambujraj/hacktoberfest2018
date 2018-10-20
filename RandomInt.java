import java.util.Scanner;

public class RandomInt{
 
  public static void main(String[] args){
   
    Scanner scan = new Scanner(System.in);
    int firstNum = 0;
    int secondNum = 0;
    int numNums = 0;
    
    System.out.println("Input three integers (separated by a space) you would like to generate random integers between (inclusive). The third number should be how many random integers you would like");
    try{
      firstNum = scan.nextInt();
      secondNum = scan.nextInt();
      numNums = scan.nextInt();
    }catch(Exception e){
      System.out.println("Please input integer values ONLY.");
    }
    
    scan.close();
    
    //Find which inputted number is smaller to make sure we have the correct range
    int smallerNum = secondNum;
    if(firstNum < secondNum){
      smallerNum = firstNum;
    }
    
    for(int i = 0; i < numNums; i++){
      System.out.print((int)(Math.random() * (Math.abs(secondNum - firstNum) + 1) + smallerNum) + " "); 
    }
    
  }
  
}
