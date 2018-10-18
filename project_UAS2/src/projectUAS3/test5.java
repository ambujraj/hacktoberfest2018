/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projectUAS3;

/**
 *
 * @author humane
 */
public class test5 {

    public static String inputString() {
        int karakter;
        String str = "";
        boolean selesai = false;
        while (!selesai);
        {
            try {
                karakter = System.in.read();
                if (karakter < 0 || (char) karakter == '\n') {
                    selesai = true;
                } else if ((char) karakter != '\r') {
                    str = str + (char) karakter;
                }
            } catch (java.io.IOException e) {
                System.out.println("Ada kesalahan");
                selesai = true;
            }

        }
        return str;
    }

}
