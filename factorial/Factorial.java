/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Prachi
 */
import java.util.Scanner;
public class Factorial 
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter number:");
        int n = in.nextInt();
        long f = fact(n,1);
        System.out.println("Factorial of " + n + " = " + f);
    }
    public static long fact(int n, long f)
    {
        if(n<0)
            return 0;
        if(n == 1 || n == 0)
            return f;
        return fact(n-1,f*n);
    }
}
