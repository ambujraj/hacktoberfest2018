/*JAVA program to find if a number is in a valid Indian mobile number format*/

import java.util.*;
import java.lang.String;
public class telephoneValidator{

//Main Driver method
     public static void main(String []args){
        //num can be replaced with any mobile number
        String num = "5845218987";
        if(validateNumber(num)){
            System.out.println("Valid mobile number");
        }else{
             System.out.println("Invalid mobile number");
        }
     }
     
 //checks if it is a valid Indian mobile number format 
     private static boolean validateNumber(String num){
         if(num.length()==11){
            char start = num.charAt(0);
            if(start!='9'||start!='8'||start!='7'||start!='6'){     //Indian mobile number generally starts with 9,8,7 or 6
                return true;
            }
         }
       return false;
     
}
}
