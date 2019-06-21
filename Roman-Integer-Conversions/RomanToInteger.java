import java.util.*;
public class RomanToInteger{
    public static void main(String args[]){
        Scanner s= new Scanner(System.in);
        String str = s.next();
        System.out.println("Integer of roman "+str+" is: "+romanToInteger(str));
      }

    public static int romanToInteger(String s) {
        String str="IVXLCDM";
        int num[]={1,5,10,50,100,500,1000};
        char ch,ch1;
          int sum=0,sub=0,i;
          for(i=0;i<a.length()-1;i++){
              ch=a.charAt(i);
              ch1=a.charAt(i+1);
              if(str.indexOf(ch1)<=str.indexOf(ch)){
                  sum=sum+num[str.indexOf(ch)];
                  sum=sum-sub;
                  sub=0;
              }
              else{
                  sub=sub+num[str.indexOf(ch)];
              }
          }
          sum=sum+num[str.indexOf(a.charAt(i))];
          sum=sum-sub;
          return sum;
    }
}
