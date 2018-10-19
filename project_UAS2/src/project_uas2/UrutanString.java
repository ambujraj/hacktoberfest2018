/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project_uas2;

/**
 *
 * @author USER
 */
public class UrutanString {
    public static void main(String[] args) {
        String[] nama = {"Jahe", "Kunyit", "Daun jabu biji", "Temulawak", "Sambiloto", "Kijibeling", "Kumis kucing", "Pegagan",
            "Daun cincau", "Lidah buaya", "Daun beluntas", "Belimbing wuluh", "Brotowali", "Daun jinten", "Kayu manis", "Seledri", "Daun kelor",
            "Daun murbei", "Sirih merah", "Daun asam", "Alang-Alang", "Daun tempuyung", "Daun andong", "Temu giring", "Akar wangi"};
        String temp;
        
        System.out.println("nama sebelum diurutkan");
        for (int i = 0; i < nama.length; i++) {
            System.out.println(i+1+" "+nama[i]+"");
        }
        System.out.println("=========================================");
        System.out.println("nama yang sudah diurutkan");
        for (int i = 0; i < (nama.length-1); i++) {
            for (int j = 0; j < nama.length-1; j++) {
                if (nama[j].compareTo(nama[j+1])>0) {
                    temp=nama[j+1];
                    nama[j+1]=nama[j];
                    nama[j]=temp;
                }
            }
        }
        for (int i = 0; i < nama.length; i++) {
            System.out.println(i+1+" "+nama[i]);
        }
    }
}
