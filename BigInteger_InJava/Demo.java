package BigInteger_InJava;


import java.math.BigInteger;

public class Demo {
    public static void main(String[] args) {
        
        BigInteger bigNum = new BigInteger("100000000000000000000000");
        long temp = 1235678900;
        
        /*Some constants also be defined in BigInteger such as*/
        
        BigInteger bI = BigInteger.TEN; // some other constants are BigInteger.ONE and BigInteger.ZERO
        
        //------------------------------------------------------
        
        System.out.println("Added value : " + bigNum.add(BigInteger.valueOf(temp)));
        
        System.out.println("Multiplied value : " + bigNum.multiply(BigInteger.valueOf(temp)));
        
        System.out.println("Divided value : " + bigNum.divide(BigInteger.valueOf(temp)));
        
        System.out.println("Subtracted value : " + bigNum.subtract(BigInteger.valueOf(temp)));
        
        System.out.println("Mod value : " + bigNum.mod(BigInteger.valueOf(temp)));
        
        System.out.println("GCD value : " + bigNum.gcd(BigInteger.valueOf(temp)));
        
        System.out.println("ABS value : " + bigNum.abs(BigInteger.valueOf(temp)));
        
        System.out.println("Divided and Remainder value : " + bigNum.divideAndRemainder(BigInteger.valueOf(temp)));
        
        
    }
}
