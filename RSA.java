import java.io.DataInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Random;

public class RSA {
    private BigInteger p; // To allow large values
    private BigInteger q;
    private BigInteger N;
    private BigInteger phi;
    private BigInteger e;
    private BigInteger d;
    private int bitlength = 1024;
    // To create random integers create instance for Random class
    private Random r;

    public RSA() {
        r = new Random();
        // The java.math.BigInteger.probablePrime(int bitLength, Random rnd) returns a
        // positive BigInteger that is probably prime, with the specified bitLength.
        p = BigInteger.probablePrime(bitlength, r);
        q = BigInteger.probablePrime(bitlength, r);
        N = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(bitlength / 2, r);
        // To generate ‘e’ so that e lies between 1 and phi
        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0) {
            e = e.add(BigInteger.ONE);
        }
        // To generate d as e-1 mod phi
        d = e.modInverse(phi);
    }

    public static void main(String[] args) throws IOException {
        RSA rsa = new RSA();
        DataInputStream in = new DataInputStream(System.in);
        String teststring;
        System.out.println("Enter the plain text:");
        teststring = in.readLine();
        System.out.println("Encrypting String: " + teststring);
        /*
         * The java.lang.Byte.toString() returns a String object representing this
         * Byte's value. The value is converted to signed decimal representation and
         * returned as a string, exactly as if the byte value were given as an argument
         * to the toString(byte) method.
         */
        System.out.println("String in Bytes: " + bytesToString(teststring.getBytes()));
        // encrypt
        byte[] encrypted = rsa.encrypt(teststring.getBytes());
        System.out.println("encrypted string in bytes " + bytesToString(encrypted));
        // decrypt
        byte[] decrypted = rsa.decrypt(encrypted);
        System.out.println("Decrypting Bytes: " + bytesToString(decrypted));
        System.out.println("Decrypted String: " + new String(decrypted));
        System.out.println("****************************************");
    }

    private static String bytesToString(byte[] encrypted) {
        String test = "";
        for (byte b : encrypted) {
            test += Byte.toString(b);
        }
        return test;
    }

    public byte[] encrypt(byte[] message) {
        return (new BigInteger(message)).modPow(e, N).toByteArray();
    }

    public byte[] decrypt(byte[] message) {
        return (new BigInteger(message)).modPow(d, N).toByteArray();
    }
}