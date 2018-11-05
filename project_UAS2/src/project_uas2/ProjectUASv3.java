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
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class tumbuhan {

    private int urutan;
    private String nama_tumbuhan;
    private String kandungan;
    private String manfaat;
    private String bahan_bahan;
    private String cara_membuat;

    public tumbuhan(int urutan, String nama_tumbuhan, String kandungan, String manfaat, String bahan_bahan, String cara_membuat) {
        this.urutan = urutan;
        this.kandungan = kandungan;
        this.manfaat = manfaat;
        this.bahan_bahan = bahan_bahan;
        this.cara_membuat = cara_membuat;
        this.nama_tumbuhan = nama_tumbuhan;
    }

    public void displaytumbuhan() {
        System.out.println(urutan + ". " + nama_tumbuhan);
    }

    public void displaykandungan() {
        System.out.println("==" + nama_tumbuhan + "==\n" + "Kandungan " + nama_tumbuhan + "\n" + kandungan + "Manfaat\n" + manfaat + "Bahan-Bahan yang diperlukan\n" + bahan_bahan + "Cara membuatnya\n" + cara_membuat);
    }

    public String getNamaTumbuhan() {
        return nama_tumbuhan;
    }

    public String getKandungan() {
        return kandungan;
    }

    public String getManfaat() {
        return manfaat;
    }

    public String getBahan_bahan() {
        return bahan_bahan;
    }

    public String getCaramembuat() {
        return cara_membuat;
    }

    class datatumbuhan {
        private tumbuhan[]tumbuh;
        private int nElemen;
        
        public datatumbuhan(int max){
            tumbuh=new tumbuhan[max];
            nElemen=0;
    }
        public void insert(int urutan, String nama_tumbuhan, String kandungan, String manfaat, String bahan_bahan, String cara_membuat){
            tumbuh[nElemen]=new tumbuhan(urutan, nama_tumbuhan, kandungan, manfaat, bahan_bahan, cara_membuat);
            nElemen++;
        }
        public String readString(){
            BufferedReader a=new BufferedReader(new InputStreamReader(System.in));
            String String = "";
            try {
                String =a.readLine();
            } catch (Exception e) {
                System.out.println(e);
            }
            return String;
        }
        public int readInt(){
            return Integer.parseInt(readString());
        }
    }
}
    public class ProjectUASv3 {
        public static void main(String[] args) {
            datatumbuhan panggil=new datatumbuhan(25);
        }
    }

