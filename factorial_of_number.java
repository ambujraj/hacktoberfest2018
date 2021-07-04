import java.util.Scanner;

class Factorial{  
 
 public static void main(String args[]){  
  
  Scanner scan = new Scanner(System.in);
  
  int i,fact=1;  
  int number = 1;
  
  try{
   number= scan.nextInt();
  }catch(Exception e){
   System.out.println("Error: Please enter an integer!");
  }
  
  scan.close();
  
  for(i = 1; i <= number; i++){    
      fact=fact*i;    
  }    
  
  System.out.println("Factorial of "+number+" is: "+fact);
  
 }  
 
}  
