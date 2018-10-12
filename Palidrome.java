class Palidrome{
public static boolean isPalindrome(int integer) {
    String intStr = String.valueOf(integer); 
    return intStr.equals(new StringBuilder(intStr).reverse().toString());
}
}
