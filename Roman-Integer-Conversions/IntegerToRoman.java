import java.util.*;
public class IntegerToRoman{
    public static void main(String args[]){
        Scanner s= new Scanner(System.in);
        int n = s.nextInt();
        System.out.println("Roman of number "+n+" is: "+intToRoman(n));    
      }

    public static String intToRoman(int A) {
        String[] str1 = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        String[] str2 = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        String[] str3 = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        String[] str4 = {"","M","MM","MMM"};
        String str = "";
        str = str4[A/1000];
        A = A%1000;
        str += str3[A/100];
        A = A%100;
        str += str2[A/10];
        A = A%10;
        str += str1[A];
        return str;
    }
}
