import java.util.*;
class harshadnumber
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Input a number");
        int num=sc.nextInt();
        int x=num,y,sum=0;
        while(x>0)
        {
            y=x%10;
            sum = sum + y;
            x = x/10;
        }
         
        if(num%sum == 0)
            System.out.println(num+" is a Harshad Number.");
        else
            System.out.println(num+" is not a Harshad Number.");      
    }
}