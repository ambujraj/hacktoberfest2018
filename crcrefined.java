import java.util.*;
public class crcrefined {
    int old,dataword,hpd,divisor,k;
    public crcrefined()
    {
        hpd=16; divisor=0b10001000000100001000000000000000;
    }
    public void Divide()
    {   
        for(int i=0; i<=16; i++) { //run loop hpd times
            k = dataword; //k is remainder 
            if((k>>>31)==1) /*Check if first bit is 1*/ k = (k)^(divisor); //if bits match XOR
            dataword = k; 
            dataword <<= 1; //to remove first bit after XOR
          }
          k>>=15; //lose leading 0's
          System.out.println("k is " + Integer.toBinaryString(k));  
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        crcrefined cr = new crcrefined();
        System.out.println("Enter Dataword");
        cr.dataword = sc.nextInt();
        System.out.println("DataWord is:  "+Integer.toBinaryString(cr.dataword));
        cr.old=cr.dataword;
        cr.dataword<<=15;
        cr.Divide();
        int n = (cr.old<<cr.hpd)|cr.k; //append k to dataword
        System.out.println("Codeword: "+n);
        System.out.println("Binary encoded: " + Integer.toBinaryString(n));
        System.out.println("Enter Codeword");
        cr.dataword = sc.nextInt();
        cr.old=cr.dataword;
        cr.Divide();
        if(cr.k==0)
        {
          cr.old>>=cr.hpd;
          System.out.println("Data recieved: "+cr.old);
          System.out.println("Binary encoded: "+Integer.toBinaryString(cr.old));
        }
        else System.out.println("Data Corrupted!"); 
        sc.close();
    }
}