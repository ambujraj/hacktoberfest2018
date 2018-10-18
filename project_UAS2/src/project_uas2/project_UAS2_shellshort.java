/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project_uas2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 *
 * @author USER
 */
public class project_UAS2_shellshort {
    String data;
    String cari = "";
    int jumlah = 0;
    public static Scanner input = new Scanner(System.in);
    //kode warna merah
    public static String ANSI_RED = "\u001B[31m";
    //kode warna hijau
    public static String ANSI_GREEN = "\u001B[32m";
    //kode warna ungu
    public static String ANSI_PURPLE = "\u001B[35m";
    //kode warna kuning
    public static String ANSI_YELLOW = "\u001B[33m";
    //kode warna biru
    public static String ANSI_BLUE = "\u001B[34m";

    //method jahe
    public static void jahe() {
        String jahe[] = {"\nKANDUNGAN JAHE\n1.Minyak atsiri zingiberena (zingirona)\n2.zingiberol\n3.kurkumen\n4.gingerol\n5.filandrena\n6.resin pahit\n7.bisabolena", "MANFAAT:\n1.Menghangatkan badan\n2.menuruntkan berat badan\n3.menjaga kondisi jantung\n4.mengatasi mabuk perjalanan\n5.mengatasi gangguan pencernaan\n6.mencegah kanker usus\n7.mengobati sakit kepala\n8.mengomati alergi\n9.mengobati penyakit rematik\n10.meningkatkan sistem kekebalan tubuh", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT WEDANG JAHE:\n1.Jahe\n2.Gula pasir atau gula merah(Sesuai selera)\n3.Air", "CARA MEMBUAT WEDANG JAHE:\n1.kupas dan cuci jahe hingga bersih\n2.Rebus air hingga mendidih\n3.Sembari menunggu air mendidih, jahe dibakar sampai kemerah-merahan\n4.Kupas bagian yang terbakar\n5.Potong kecil-kecil dan dipukul agar aromanya keluar\n6.Masukan jahe yang telah di pukul ke dalam gelas\n7. Masukan gula secukupnya kedalam gelas\n8.Tuangkan air yang sudah dimasak tadi aduk hingga rata\n9.Hidangkan saat masih panas"};
        for (int i = 0; i < jahe.length; i++) {
            System.out.println(ANSI_RED + "==JAHE==" + jahe[i]);

        }
    }

    //method kunyit
    public static void kunyit() {
String kunyit[] = {"\nKANDUNGAN KUNYIT:\n1.kurkumin\n2.desmetoksikumin\n3.bisdesmetoksikurkumin\n4.Keton sesquiterpen\n5.turmeron\n6.Zingiberen", "MANFAAT:\n1.Sebagai ramuan anti peradangan tubuh\n2.Mengobati penyakit asam lambung\n3.Mengurangi gas pada pencernaan\n4.Meredakan sakit akibat irritable bowel syndrom\n5.Mengurangi mual\n6.Meredakan diare", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT JAMU KUNYIT:\n1.Empat gelas air\n2.Satu sendok teh kunyit parutan kunyit\n3.Lemon atau madu untuk ditambahkan pada tahap akhir", "CARA MEMBUAT JAMU KUNYIT:\n1.Rebus 4 gelas air sampai mendidih\n2.Masukkan 1 sendok teh kunyit ke air yang sedang mendidih\n3.Kecilkan api dan biarkan air yang sudah dicampur kunyit tersebut mendidih selama sekitar 10 menit\n4.Matikan api dan saring air kunyit tersebut menggunakan saringan yang halus\n5.Tuangkan hasil saringan tersebut ke dalam gelas dan tambahkan lemon atau madu sesuai selera"};
        for (int i = 0; i < kunyit.length; i++) {
            System.out.println(ANSI_GREEN + "==KUNYIT==" + kunyit[i]);
        }
    }

    //method daun jambu biji
    public static void daunjambubiji() {
        String daunjambubiji[] = {"\nKANDUNGAN DAUN JAMBU BIJI:\n1.Saponin\n2.Flavanoid\n3.Polifenol\n4.Alkaloid\n5.Karoten\n6.Steroid\n7.Kuinon\n8.Anti-oksidan\n9.Minyak atsiri\n10.Tannin\n11.Senyawa anti-mutagenic", "MANFAAT:\n1.Mengobati diare dan disentri\n2.Diabetes Mellitus\n3.Mengobati Luka Memar\n4.Mengatasi Jerawat\n5.Mengatasi Komedo\n6.Ambeien\n7.Mengusir kembung", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN JAMBU BIJI:\n1.Siapkan 7-10 lembar daun jambu biji\n2.Air", "CARA MEMBUAT AIR SEDUHAN DAUN JAMBU BIJI:\n1.Cuci bersih daun tersebut dalam air yang mengalir\n2.Rebus 2-3 gelas air minum, setelah mendidih masukan daun jambu biji terlebus\n3.Rebus hingga air tersisa setengahnya sambil sesekali di aduk\n4.Setelah dingin ramuan air rebusan siap untuk di minum"};
        for (int i = 0; i < daunjambubiji.length; i++) {
            System.out.println(ANSI_PURPLE + "==DAUN JAMBU BIJI==" + daunjambubiji[i]);
        }
    }

    //method temulawak
    public static void temulawak() {
        String temulawak[] = {"\nKANDUNGAN TEMULAWAK:\n1.Magnesium\n2.Phosphorus\n3.Zinc\n4.Asam folat\n5.Vitamin A\n6.Vitamin D", "MANFAAT:\n1.Memelihara Fungsi Hati\n2.Mengurangi radang sendi\n3.Masalah pencernaan\n4.Membantu Menurunkan Lemak Darah\n5.Melawan Kanker", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT JAMU TEMULAWAK:\n1.satu jari, rimpang temulawak iris-iris\n2.Sepuluh lembar, daun ungu\n3.Sstu gelas air putih 200ml", "CARA MEMBUAT JAMU TEMULAWAK:\n1.Bersihkan rimpang temulawak dengan daun ungu hingga bersih\n2.Setelah itu, rebus kedua bahan tersebut hingga mendidih\n3.Kemudian, angkat dan dinginkan lalu sharing\n4.Minum ramuan tersebut secara rutin 2 kali sehari sebanyak setengah gelas"};
        for (int i = 0; i < temulawak.length; i++) {
            System.out.println(ANSI_YELLOW + "==TEMULAWAK==" + temulawak[i]);
        }
    }

    //method sambiloto
    public static void sambiloto() {
        String sambiloto[] = {"\nKANDUNGAN SAMBILITO:\n1.Andrographolide\n2.Saponin\n3.Falvonoid\n4.Alkanoid\n5.Tanin\n6.Laktone\n7.Panikulin\n8.Kalmegin\n9.Hablur kuning", "MANFAAT:\n1.Dapat mengobati hepatitis\n2.Mengobati disentri basiler\n3.Mengobati sakit gigi\n4.Mengobati demam\n5.Mengobati Malaria", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN SAMBILOTO:\n1.Daun sambiloto\n2.Air", "CARA MEMBUAT AIR SEDUHAN DAUN SAMBILOTO:\n1.Daun sambiloto segar sebanyak satu genggam\n2.Ditumbuk rata kemudian ditambahkan air matang sebanyak 110mL\n3.Saring kemudian minum sekaligus"};
        for (int i = 0; i < sambiloto.length; i++) {
            System.out.println(ANSI_BLUE + "==SAMBILOTO==" + sambiloto[i]);
        }
    }

    //method kijibeling
    public static void kijibeling() {
        String kijibeling[] = {"\nKANDUNGAN KIJIBELING:\n1.Tripenoid\n2.Fosfor\n3.Natrium\n4.Kafein\n5.Kalsium\n6.Asam silikat\n7.Potassium", "MANFAAT:\n1.Menjaga kesehatan ginjal\n2.Diuretic alami\n3.Meningkatkan volume darah\n4.Mempercepat proses pembekuan darah\n5.Menghambat pertumbuhan kanker\n6.Mengatasi diare serta disentri\n7.Menjaga kesehatan organ hati\n8.Menurunkan kolestrol", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN KIJIBELING:\n1.Siapkan daun kijibeling sekitar 5-6 lembar\n2.Air", "CARA MEMBUAT AIR SEDUHAN DAUN KIJIBELING:\n1.Rebus air bersamaan dengan daun kijibeling\n2.Tunggu hingga air setengah\n3.Setelah itu, angkat dan dinginkan\n4.Setelah dingin, minum ramuan tersebut dua kali sehari"};
        for (int i = 0; i < kijibeling.length; i++) {
            System.out.println(ANSI_RED + "==KIJIBELING==" + kijibeling[i]);
        }
    }

    //method kumis kucing
    public static void kumiskucing() {
        String kumiskucing[] = {"\nKADUNGAN TUMBUHAN KUMIS KUCING:\n1.Garam kalium\n2.Glikosida Orthosiphonim\n3.Mioinositol\n4.Minyak Atsiri\n5.Saponin\n6.Sapofonim\n7.Sinensetis\n8.Zat samak", "MANFAAT:\n1.Melancarkan air seni\n2.Mengobati batuk\n3.Mengobati sembelit\n4.Mengobati diabetes\n5.Mengobati gatal karena alergi", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN TUMBUHAN KUMIS KUCING:\n1.Siapkan 90 gr daun kumis kucing segar\n2.Satu gelas air putih", "CARA MEMBUAT AIR SEDUHAN DAUN TUMBUHAN KUMIS KUCING:\n1.Cuci daun kumis kucing sampai bersih\n2.Rebus daun kumis kucing  tersebut dengan air hingga airnya tersisa 1/2 gelas saja\n3.Minum ramuan tersebut  sebanyak 3x sehari dengan dosis 1/2 gelas"};
        for (int i = 0; i < kumiskucing.length; i++) {
            System.out.println(ANSI_GREEN + "==KUMIS KUCING==" + kumiskucing[i]);
        }
    }

    //method pegagan
    public static void pegagan() {
        String pegagan[] = {"\nKANDUNGAN PEGAGAN:\n1.brahmoside\n2.brahmic acid\n3.brahminosid\n4.asiaticoside\n5.madecassoside\n6.madasiatic acid\n7.centelloside", "MANFAAT:\n1.Mengobati sariawan dan panas dalam\n2.Menghilangkan jerawat dan menghaluskan wajah\n3.Sebagai pembersih alami\n4.Melancarkan sirkulasi darah\n5.Menurunkan demam\n6.Meningkatkan tenaga dan stamina tubuh\n7.Meningkatkan sistem saraf ingatan", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN PEGAGAN\n1.Satu genggam daun pegagan\n2.Lima batang tapak lima\n3.Setengah genggam, daun jintan hitam\n4. Satu sendok madu\n5. Satu gelas air putih 200mL", "CARA MEMBUAT SEDUHAN DAUN PEGAGAN:\n1.Cuci bersih semua bahan, lalu masukan dalam panci bersama satu gelas air\n2.Setelah itu rebus hingga mendidih\n3.Selanjutnya saring ainya dan beri campuran madu, aduk sampai rata\n4.Angkat dan minum air ramuan tersebut secara rutin sehari 2 kali pagi dan sore"};
        for (int i = 0; i < pegagan.length; i++) {
            System.out.println(ANSI_PURPLE + "==PEGAGAN==" + pegagan[i]);
        }
    }

    //method daun cincau
    public static void dauncincau() {
        String dauncincau[] = {"\nKANDUNGAN DAUN CINCAU:\n1.Serat Makanan\n2.Fosfor\n3.Vitamin A\n4.Vitamin B1\n5.Vitamin C\n6.Protein\n7.Lemak\n8.Karbohidrat\n9.Energi", "MANFAAT:\n1.Mengobati sakit perut dan tekanan darah tinggi\n2.Mengobati demam\n3.Mengobati penyakit kanker", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT CINCAU:\n1.Air matang 300 mL\n2.Daun cincau 40 lembar yang sedang, cuci bersih", "CARA MEMBUAT CINCAU:\n1.Petama-tama remas-remas daun cincau segar\n2.Tuanglah 1/2 bagian air sedikit demi sedikit sambil terus diremas-remas sampai keluar lendir/gel berwarna hijau\n3.Selanjutnya saring remasan daun cincau\n4.Kemudian remas-remas kembali ampas (daun cincau) sambil tuang sisa air sampai keluar lendirnya. Setelah itu saring\n5.Nah sekarang simpan hasil saringan daun cincau dalam lemari pendingin sampai beku selama kurang lebih 3-4 jam\n6.Cincau hijau siap digunakan, bisa diolah lanjutan menjadi es cincau segar"};
        for (int i = 0; i < dauncincau.length; i++) {
            System.out.println(ANSI_YELLOW + "==DAUN CINCAU==" + dauncincau[i]);
        }
    }

    //method lidah buaya
    public static void lidahbuaya() {
        String lidahbuaya[] = {"\nKANDUNGAN LIDAH BUAYA:\n1.Energi\n2.Protein\n3.Karbohidrat\n4.Kalsium\n5.Zat besi\n6.Vitamin A\n7.Vitamin B\n8.Vitamin C\n8.Fosfor", "MANFAAT:\n1.Penyubur rambut\n2.Sebagai anti oksidan\n3.Menghilangkan ketombe\n4.Detoksifikasi\n5.Menjaga kesehatan mulut\n6.Menjaga berat badan\n7.Mengobati wasir\n8.Menghilangkan jerawat", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT NATA DE ALOE VERA:\n1.Daun lidah buaya\n2.Garam\n3.Air", "CARA MEMBUAT NATA DE ALOE VERA:\n1.Daun lidah buaya dipotong sekitar per 10 cm menjadi 5 potong\n2.Hilangkan kulit yang berwarna hijau, tinggalkan dagaing ynag berwarna bening\n3.Dari potongan memanjang potong lagi menjadi kotak-kotak seperti nata de coco\n4.Kemudian cuci berulang-ulang sampai lendirnya habis\n5.Tambahkan garam dalam pencucian mungkin 2 sampai 3 kali saat membilasnya\n6.Kemudian rebuslah, tunggu 15 menit selama mendidih, setelah itu angkat, untuk mengurangi bau dapat ditambahkan daun pandan"};
        for (int i = 0; i < lidahbuaya.length; i++) {
            System.out.println(ANSI_BLUE + "==LIDAH BUAYA==" + lidahbuaya[i]);
        }
    }

    //method daun beluntas
    public static void daunbeluntas() {
        String daunbeluntas[] = {"\nKANDUNGAN DAUN BELUNTAS:\n1.Alkanoid\n2.Pluchine\n3.Asam kafeoilkuniat\n4.Saponin\n5.polifenol\n6.Tannin\n7.Asam amino\n8.Kalsium\n9.Fosfor\n10.Vitamin A\n11.Vitamin C", "MANFAAT:\n1.Mengobati pencernaan pada anak-anak\n2.Mengatasi TBC kelenjar leher\n3.Mengatasi nyeri rematik\n4.Menghilangkan bau badan dan bau mulut\n5.Obat keputihan\n6.Mengatasi masalah hipertensi\n7.Melancarkan haid", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN BELUNTAS:\n1.Siapkan beberapa helai daun beluntas 3-5 lembar\n2.Air", "CARA MEMBUAT AIR SEDUHAN DAUN BELUNTAS:\n1.Cuci daun beluntas sampai benar-benar bersih, kemudian rebus dengan 2 gelas air bersih\n2.Tunggu sampai mendidih hingga tersisa 1 gelas\n3.Angkat dan kemudian diamkan sampai menjadi hangat, minumlah secara rutin pagi dan sore hari"};
        for (int i = 0; i < daunbeluntas.length; i++) {
            System.out.println(ANSI_PURPLE + "==DAUN BELUNTAS==" + daunbeluntas[i]);
        }
    }

    //method belimbing wuluh
    public static void belimbingwuluh() {
        String belimbingwuluh[] = {"\nKANDUNGAN BELIMBING WULUH:\n1.Glukosid\n2.Tanin\n3.Asam folat\n4.Peroksida\n5.Kalsium oksalat\n6.Sulfur\n7.Kalium sitrat", "MANFAAT:\n1.Obat sariawan dan mengatasi gusi berdarah\n2.Melancarkan pencernaan\n3.Menghaluskan kulit wajah\n4.Menyembuhkan batuk\n5.Menyembuhkan gondongan\n6.Mencegah penyakit kanker\n7.Mengatasi hipertensi\n8.Mengatasi rematik", "BAHAN-BAHAN YANG DIPERLUKAN BUAT SIRUP BELIMBING WULUH:\n1.200 gram belimbing wuluh yang segar dan sudah dicuci\n2. Satu setengah air putih\n3.Madu secukupnya\n4.Es batu secukupnya", "CARA MEMBUAT SIRUP BELIMBING WULUH:\n1.Potong kecil-kecil buah belimbing wuluh\n2.Masukan semua bahan ke dalam bender, lalu bender hingga halus\n3.Tuang jus kedalam gelas saji\n4.Jus belimbing siap untuk disajikan"};
        for (int i = 0; i < belimbingwuluh.length; i++) {
            System.out.println(ANSI_RED + "==BELIMBING WULUH==" + belimbingwuluh[i]);
        }
    }

    //method brotowali
    public static void brotowali() {
        String brotowali[] = {"\nKANDUNGAN BROTOWALI:\n1.Glikosida pikroretosid\n2.Harsa\n3.Berberin\n4.Palmatin\n5.Alkaloid berberin", "MANFAAT:\n1.Mengobati rematik\n2.Mengobati demam kuning\n3.Mengobati diabetes\n4.Mengobati kudis\n5.Mengobati luka", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN AIR BROTOWALI:\n1.6cm batang brotowali\n2.Sepertiga genggam daun kumis kucing\n3.Sepertiga daun sambiloto\n4.Tiga gelas air", "CARA MEMBUAT SEDUAN AIR BROTOWALI:\n1.Cuci bersih dan potong-potong semua herba\n2.Rebuslah semua herba dengan 3 gelas air hingga mendidih dan tersisa 2 gelas air\n3.Setelah dingin, saring dan minum 1 gelas setelah makan 2 kali sehari"};
        for (int i = 0; i < brotowali.length; i++) {
            System.out.println(ANSI_YELLOW + "==BROTOWALI==" + brotowali[i]);
        }
    }

    //method daun jinten
    public static void daunjinten() {
        String daunjinten[] = {"\nKANDUNGAN DAUN JINTEN:\n1.Minyak atsiri\n2.Fenol\n3.Kalium", "MANFAAT:\n1.Mengembalikan kekebalan tubuh\n2.Obat demam\n3.Mengobati asma\n4.Sebagai obat batuk\n5.Mengobati penyakit stroke\n6.Mengobati rematik\n7.Mengobati perut kembung", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN DAUN JINTEN:\n1.Siapkan 6 lembar daun jinten\n2.Air", "CARA MEMBUAT AIR SEDUHAN DAUN JINTEN:\n1.Cuci bersih daun jinten kemudian tumbuklah sampai halus\n2.Rebuslah air hingga mendidih\n3.Setelah air mendidih angkat kemudian tuangkan air ke dalam gelas yang sudah berisi daun jinten\n4.Air seduhan daun jinten siap dihidangkan"};
        for (int i = 0; i < daunjinten.length; i++) {
            System.out.println(ANSI_BLUE + "==DAUN JINTEN==" + daunjinten[i]);
        }
    }

    //method kayu manis
    public static void kayumanis() {
        String kayumanis[] = {"\nKANDUNGAN KAYU MANIS:\n1.Eugenol\n2.Minyak atsiri\n3.tanin\n4.Sinamaldehide\n5.Kalsium oksalat\n6.Safrole\n7.Zat penyamak dan damar", "MANFAAT:\n1.Mengurangi rasa nyeri haid\n2.Mencegah terjadinya penggumpalan darah\n3.Mengurangi sakit rematik\n4.Mencegah penyakit jantung\n5.Menghangatkan tubuh\n6.Mengontrol gula darah", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT:\n1.Siapkan  1 batang  kayu manis\n2.Madu\n3.Air secukupnya", "CARA MEMBUAT AIR SEDUHAN KAYU MANIS:\n1.Rebuslah air selama kurang lebih 5 menit\n2.Kemudian masukan kayu manis ke dalam air yang direbus\n3.Setelah itu tuangkan ke dalam gelas\n4.Tambahkan madu supaya lebih nikmat\n5.Air seduhan kayu manis siap dihidangkan"};
        for (int i = 0; i < kayumanis.length; i++) {
            System.out.println(ANSI_GREEN + "==KAYU MANIS==" + kayumanis[i]);
        }
    }

    //method seledri
    public static void seledri() {
        String seledri[] = {"\nKANDUNGAN SELEDRI:\n1.Kalium\n2.Folat\n3.Kalsium\n4.Vitamin K\n5.Serat", "MANFAAT:\n1.Mengobati rematik\n2.Mengobati anemia\n3.Mengobati batuk\n4.Memerangi kanker\n5.Menurunkan tekanan darah tinggi\n6.Mencegah asma\n7.Mencegah sembelit", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT AIR SEDUHAN SELEDRI:\n1.Daun seledri\n2.Air 3 gelas", "CARA MEMBUAT AIR SEDUHAN SELEDRI:\n1.Saipkan daun seledri\n2.Cuci hingga bersih\n3.Kemudian potong-potong\n4.Tuangkan 3 gelas kedalam panci\n5.Masukan daun seledri\n6.Tunggu airnya hingga menjadi 1 gelas:\n7.Air seduhan seledri siap diminum"};
        for (int i = 0; i < seledri.length; i++) {
            System.out.println(ANSI_RED + "==SELEDRI==" + seledri[i]);
        }
    }

    //method daun kelor
    public static void daunkelor() {
        String daunkelor[] = {"\nKANDUNGAN DAUN KELOR:\n1.Protein\n2.Fosfor\n3.Zat besi\n4.Kalsium\n5.Vitamin B1\n6.Vitamin C\n7.Vitamin A", "MANFAAT:\n1.Antimikroba\n2.Mencegah rematik\n3.Mengobati demam\n4.Mengobati anemia\n5.Mengobati diabetes\n6.Mengobati cacingan", "BAHAN-BAHAN YANG DIPERLUKAN UTNUK MEMBUAT TEH DAUN KELOR:\n1.Daun kelor yang sudah di keringkan\n2.Air secukupnya\n3.Madu", "CARA MEMBUAT TEH DAUN KELOR:\n1.Siapkan daun kelor yang sudah di keringkan\n2.Rebus air hingga mendidih\n3.Kemudian masukan air ke dalam gelas yang sudah berisi daun kelor\n4.Setelah itu saring daun kelor tersebut\n5.Air teh daun kelor siap dihidangkan"};
        for (int i = 0; i < daunkelor.length; i++) {
            System.out.println(ANSI_PURPLE + "==DAUN KELOR==" + daunkelor[i]);
        }
    }

    //method daun murbei
    public static void daunmurbei() {
        String daunmurbei[] = {"\nKANDUNGAN DAUN MURBEI:\n1.Eugenol\n2.Betahexenal\n3.Benzaidehide\n4.Vitamin A\n5.Vitamin B1\n6.Vitamin C\n7.Karoten", "MANFAAT:\n1.Mengobati tekanan darah tinggi\n2.Mengobati rematik\n3.Mengobati hepatitis kronis\n4.Menggobati gigitan ular\n5.Mengobati jantung lemah", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT TEH MURBEI:\n1.Pucuk daun teh murbei yang sudah kering\n2.Air secukup nya", "CARA MEMBUAT TEH MURBEI:\n1.Siapkan pucuk daun teh murbei yang sudah di keringkan\n2.Rebus air hingga mendidih\n3.Tuangkan air kedalam gelas yang sudah berisi daun murbei\n4.Kemudian saring, dan teh daun murbei sudah siap diminum"};
        for (int i = 0; i < daunmurbei.length; i++) {
            System.out.println(ANSI_YELLOW + "==DAUN MURBEI==" + daunmurbei[i]);
        }
    }

    //method sirih merah
    public static void sirihmerah() {
        String sirihmerah[] = {"\nKANDUNGAN SIRIH MERAH:\n1.Allyprokatekol\n2.Alkaloid\n3.Cineole\n4.Extragol\n5.Eugenol\n6.Fenil propoda\n7.Minyak atsiri", "MANFAAT:\n1.Mengobati Mata merah\n2.Mengobati gusi berdarah\n3.Mengobati penyakit bronkitis\n4.Mengobati darah tinggi\n5.Mengobati batuk\n6.Mengobati tumor\n7.Mengobati diabetes", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN DAUN SIRIH MERAH:\n1.Sirih merah secukupnya\n2.Air secukupnya", "CARA MEMBUAT SEDUHAN DAUN SIRIH MERAH:\n1.Siapkan sirih merah\n2.Rebus Air hingga mendidih\n3.Kemudain masukan sirih merah ke dalam air mendidih\n4.Saring air seduhan sirih merah dan tuangkan ke dalam gelas\n5.Air seduhan sirih merah siap diminum"};
        for (int i = 0; i < sirihmerah.length; i++) {
            System.out.println(ANSI_BLUE + "==SIRIH MERAH==" + sirihmerah[i]);
        }
    }

    //method daun asam
    public static void daunasam() {
        String daunasam[] = {"\nKANDUNGAN DAUN ASAM:\n1.Flavanoid\n2.Asam askorbat\n3.Tanin\n4.Vitamin C", "MANFAAT:\n1.Sebagai obat asma\n2.Sebagai obat batuk kering\n3.Mengobati malaria\n4.Menyembuhkan peradangan\n5.Mencegah penyakit kuning", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN DAUN ASAM:\n1.Segenggam daun asam\n2.Lima ruas kunyit\n3.Air secukupnya", "CARA MEMBUAT SEDUHAN DAUN ASAM:\n1.Tumbuk 1 genggam daun asam dan 5 ruas kunyit\n2.Rebus dengan air 300 cc hinggan menjadi 200 cc\n3.Kemudian tuangkan kedalam gelas\n4.Supaya lebih nikmat tambahkan gula aren secukupnya\n5.Diamkan hingga dingin lalu minum"};
        for (int i = 0; i < daunasam.length; i++) {
            System.out.println(ANSI_GREEN + "==DAUN ASAM==" + daunasam[i]);
        }
    }

    //method alang-alang
    public static void alangalang() {
        String alangalang[] = {"\nKANDUNGAN ALANG-ALANG:\n1.Silindrin\n2.Isoarbolinol\n3.Simiarenol\n4.Fernenol\n5.Arundoin\n6.Asam klorogenat\n7.Katekol\n8.Asam Isoklorogenat\n9.Asam oksalat\n10.Asam asetat\n11.Asam sitrat", "MANFAAT:\n1.Sebagai obat asma\n2.Mengobati hepatitis\n3.Mengobati diare\n4.Penyakit jantung\n5.Infeksi ginjal\n6.Demam\n7.Hipertensi", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN ALANG-ALANG:\n1.Air mineral 2 gelas\n2.Alang-alang secukupnya", "CARA MEMBUAT SEDUHAN ALANG-ALANG:\n1.Siapkan alang-alang secukupnya\n2.Cuci terlebih dulu alang-alang hingga bersih\n3.Potong kecil alang-alang\n4.Rebus hingga mendidih\n5.Terakhir angkat, diinginkan dan saring ampasnya\n6.Air rebusan alang-alang siap diminum"};
        for (int i = 0; i < alangalang.length; i++) {
            System.out.println(ANSI_RED + "==ALANG-ALANG==" + alangalang[i]);
        }
    }

    //method daun tempuyung
    public static void dauntempuyung() {
        String dauntempuyung[] = {"\nKANDUNGAN DAUN TEMPUYUNG:\n1.Flavanoid\n2.Taraksasterol\n3.Inositol\n4.Kumarin\n5.Asam fenolat", "MANFAAT:\n1.Mengobati kencing batu\n2.Mengobati asam urat\n3.Mengobati wasir\n4.Mengobati wasir", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN DAUN TEMPUYUNG:\n1.Air mineral\n2.Daun tempuyung secukupnya", "CARA MEMBUAT SEDUHAN DAUN TEMPUYUNG:\n1.Siapkan daun tempuyung yang masih segar\n2.Cuci terlebih dahulu hingga bersih\n3.Seduh hingga medidih\n4.Saring dan kemudian dinginkan\n5.Air daun tempuyung siap diminum"};
        for (int i = 0; i < dauntempuyung.length; i++) {
            System.out.println(ANSI_PURPLE + "==DAUN TEMPUYUNG==" + dauntempuyung[i]);
        }
    }

    //method daun andong
    public static void daunandong() {
        String daunandong[] = {"\nKANDUNGAN DAUN ANDONG:\n1.Saponin\n2.Tanin\n3.Flavonoid\n4.Polifenol\n5.Steroida\n6.Kalsium oksalat\n7.Zat besi", "MANFAAT:\n1.Mengobati radang gusi\n2.Mengobati diare\n3.Mengobati wasir", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT DAUN TEMPUYUNG:\n1.Air mineral\n2.Daun andong secukupnya", "CARA MEMBUAT SEDUHAN DAUN ANDONG:\n1.Siapkan daun andong yang masih segar\n2.Cuci hingga bersih\n3.Masukan daun andong kemudian rebus hingga mendidih\n4.Saring daun andong dan dinginkan\n5.Air daun andong siap untuk diminum"};
        for (int i = 0; i < daunandong.length; i++) {
            System.out.println("==DAUN ANDONG==" + daunandong[i]);
        }
    }

    //method temu giring
    public static void temugiring() {
        String temugiring[] = {"\nKANDUNGAN TEMU GIRING:\n1.Tannin\n2.Minyak atsiri\n3.Flavonoida\n4.Piperazin sitrat\n5.Damar\n6.Kurkumin\n7.Protein\n8.Lemak", "MANFAAT:\n1.Mengobati cacingan\n2.Obat sakit perut\n3.Mengobati cacar air\n4.Mengobati kudis", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT JAMU TEMU GIRING:\n1.Air mineral\n2.Temu giring\n3.Madu", "CARA MEMBUAT JAMU TEMU GIRING:\n1.Cuci temu giring hingga bersih\n2.Parut temu ginring hingga halus\n3.Masukan hasil arutan kedalam gelas\n4.Rebus air hingga mendidih\n5.Tuangkan air ke dalam gelas yang berisi hasil parutan temu giring\n6.Saring dan tambahkan madu supaya lebih nikmat\n7.Jamu temu giring siap diminum"};
        for (int i = 0; i < temugiring.length; i++) {
            System.out.println("==TEMU GIRING==" + temugiring[i]);
        }
    }

    //method akar wangi
    public static void akarwangi() {
        String akarwangi[] = {"\nKANDUNAGN AKAR WANGI:\n1.Senyawa karbonil\n2.Ester\n3.Vetiveron\n4.Seskuiterpen\n5.Seskuiterpen derivatif", "MANFAAT:\n1.Mengatasi bau mulut\n2.Mengobati rematik\n3.Mengobati batu ginjal\n4.Menurunkan demam", "BAHAN-BAHAN YANG DIPERLUKAN UNTUK MEMBUAT SEDUHAN AKAR WANGI:\n1.Akar wangi secukupnya\n2.Air secukupnya\n3.Garam", "CARA MEMBUAT SEDUHAN AKAR WANGI:\n1.Cuci terlebih dahulu akar wangi\n2.Potong-potong akar wangi, rebus dengan air sampai mendidih\n3.Masukan garam secukupnya\n4.Tunggu hingga air mengeluarkan wangi\n5.Tuangkan air di gelas tunggu hingga hangat\n6.Air akar wangi siap untuk diminum"};
        for (int i = 0; i < akarwangi.length; i++) {
            System.out.println(ANSI_GREEN + "==AKAR WANGI==" + akarwangi[i]);
        }
    }

 
        String[] datatumbuhan = {"Jahe", "Kunyit", "Daun jabu biji", "Temulawak", "Sambiloto", "Kijibeling", "Kumis kucing", "Pegagan",
            "Daun cincau", "Lidah buaya", "Daun beluntas", "Belimbing wuluh", "Brotowali", "Daun jinten", "Kayu manis", "Seledri", "Daun kelor",
            "Daun murbei", "Sirih merah", "Daun asam", "Alang-Alang", "Daun tempuyung", "Daun andong", "Temu giring", "Akar wangi"};
      

    public  void shellsort(){
        int in,out;
        datatumbuhan
    }
    public static void display(String []a){
        for (int i = 0; i < a.length; i++) {
            System.out.println((i+1)+" " + a[i]);
        }
    }
    public  void daftar() {
        int data;
        int pilih;
        String ulang2;
        try {
            do {
                String ulang;
                BufferedReader a = new BufferedReader(new InputStreamReader(System.in));
                System.out.println("Selamat datang di aplikasi tanaman TOGA");
                System.out.println(ANSI_BLUE + "1.Silahkan pilih daftar tumbuhan\n" + ANSI_RED + "2.Pencaharian berdasarkan penyakit\n"+"3.Sorting berdasarkan abjad");
                System.out.print("Silahkan dipilih: ");
                data = Integer.parseInt(a.readLine());
                do {
                    //kode ketika memilih pilihan 1
                    if (data == 1) {
//                        String[] datatumbuhan = {"Jahe", "Kunyit", "Daun jabu biji", "Temulawak", "Sambiloto", "Kijibeling", "Kumis kucing", "Pegagan",
//                            "Daun cincau", "Lidah buaya", "Daun beluntas", "Belimbing wuluh", "Brotowali", "Daun jinten", "Kayu manis", "Seledri", "Daun kelor",
//                            "Daun murbei", "Sirih merah", "Daun asam", "Alang-Alang", "Daun tempuyung", "Daun andong", "Temu giring", "Akar wangi"};
                        for (int i = 0; i < datatumbuhan.length; i++) {
                            System.out.println((i + 1) + ". " + datatumbuhan[i]);
                        }
//                        System.out.println("1.Jahe");
//                        System.out.println("2.Kunyit");
//                        System.out.println("3.Daun jambu biji");
//                        System.out.println("4.Temulawak");
//                        System.out.println("5.Sambiloto");
//                        System.out.println("6.Kijibeling");
//                        System.out.println("7.Kumis kucing");
//                        System.out.println("8.Pegagan");
//                        System.out.println("9.Daun cincau");
//                        System.out.println("10.Lidah buaya");
//                        System.out.println("11.Daun beluntas");
//                        System.out.println("12.Belimbing wuluh");
//                        System.out.println("13.Brotowali");
//                        System.out.println("14.Daun jinten");
//                        System.out.println("15.Kayu manis");
//                        System.out.println("16.Seledri");
//                        System.out.println("17.Daun kelor");
//                        System.out.println("18.Daun murbei");
//                        System.out.println("19.Sirih merah");
//                        System.out.println("20.Daun asam");
//                        System.out.println("21.Alang-alang");
//                        System.out.println("22.Daun tempuyung");
//                        System.out.println("23.Daun andong");
//                        System.out.println("24.Temu giring");
//                        System.out.println("25.Akar wangi");
                        System.out.print(ANSI_BLUE + "Silahkan pilih daftar tumbuhan diatas:");
                        pilih = input.nextInt();
                        System.out.println("");
                        //kode memilih tanaman herbal menggunakan angka
                        switch (pilih) {
                            case 1:
                                jahe();
                                break;
                            case 2:
                                kunyit();
                                break;
                            case 3:
                                daunjambubiji();
                                break;
                            case 4:
                                temulawak();
                                break;
                            case 5:
                                sambiloto();
                                break;
                            case 6:
                                kijibeling();
                                break;
                            case 7:
                                kumiskucing();
                                break;
                            case 8:
                                pegagan();
                                break;
                            case 9:
                                dauncincau();
                                break;
                            case 10:
                                lidahbuaya();
                                break;
                            case 11:
                                daunbeluntas();
                                break;
                            case 12:
                                belimbingwuluh();
                                break;
                            case 13:
                                brotowali();
                                break;
                            case 14:
                                daunjinten();
                                break;
                            case 15:
                                kayumanis();
                                break;
                            case 16:
                                seledri();
                                break;
                            case 17:
                                daunkelor();
                                break;
                            case 18:
                                daunmurbei();
                                break;
                            case 19:
                                sirihmerah();
                                break;
                            case 20:
                                daunasam();
                                break;
                            case 21:
                                alangalang();
                                break;
                            case 22:
                                dauntempuyung();
                                break;
                            case 23:
                                daunandong();
                                break;
                            case 24:
                                temugiring();
                                break;
                            case 25:
                                akarwangi();
                                break;
                        }
                    }
                    //kode ketika memilih pilihan ke-2
                    if (data == 2) {
                        System.out.println("Silahkan masukan keluhan kesehatan yang ingin anda cari");
                        String nilai = a.readLine();
                        System.out.println("");
                        if (nilai.equals("Batuk") || nilai.equals("batuk")) {
                            kumiskucing();
                            System.out.println("");
                            System.out.println("");
                            belimbingwuluh();
                            System.out.println("");
                            System.out.println("");
                            daunjinten();
                            System.out.println("");
                            System.out.println("");
                            seledri();
                            System.out.println("");
                            System.out.println("");
                            sirihmerah();
                            System.out.println("");
                            System.out.println("");
                            daunasam();

                        } else if (nilai.equals("Malaria") || nilai.equals("malaria")) {
                            sambiloto();
                            System.out.println("");
                            System.out.println("");
                            daunasam();
                        } else if (nilai.equals("Diabetes") || nilai.equals("diabetes")) {
                            kayumanis();
                            System.out.println("");
                            System.out.println("");
                            daunjambubiji();
                            System.out.println("");
                            System.out.println("");
                            kumiskucing();
                            System.out.println("");
                            System.out.println("");
                            brotowali();
                            System.out.println("");
                            System.out.println("");
                            daunkelor();
                            System.out.println("");
                            System.out.println("");
                            sirihmerah();
                        } else if (nilai.equals("Darah Tinggi") || nilai.equals("darah tinggi") || nilai.equals("Hipertensi") || nilai.equals("hipertensi")) {
                            daunbeluntas();
                            System.out.println("");
                            System.out.println("");
                            seledri();
                            System.out.println("");
                            System.out.println("");
                            dauncincau();
                            System.out.println("");
                            System.out.println("");
                            daunmurbei();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                        } else if (nilai.equals("Asma") || nilai.equals("asma")) {
                            daunjinten();
                            System.out.println("");
                            System.out.println("");
                            seledri();
                            System.out.println("");
                            System.out.println("");
                            daunasam();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                        } else if (nilai.equals("Alergi") || nilai.equals("alergi")) {
                            jahe();
                            System.out.println("");
                            System.out.println("");
                            kumiskucing();
                        } else if (nilai.equals("Komedo") || nilai.equals("komedo")) {
                            daunjambubiji();
                        } else if (nilai.equals("Gagal ginjal") || nilai.equals("gagal ginjal")) {
                            kijibeling();
                        } else if (nilai.equals("Sariawan") || nilai.equals("sariawan")) {
                            pegagan();
                            System.out.println("");
                            System.out.println("");
                            belimbingwuluh();
                        } else if (nilai.equals("Kembung") || nilai.equals("kembung")) {
                            daunjambubiji();
                            System.out.println("");
                            System.out.println("");
                            daunjinten();
                        } else if (nilai.equals("Panas dalam") || nilai.equals("panas dalam")) {
                            pegagan();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                        } else if (nilai.equals("Sembelit") || nilai.equals("sembelit")) {
                            kumiskucing();
                            System.out.println("");
                            System.out.println("");
                            seledri();
                        } else if (nilai.equals("Tumor") || nilai.equals("tumor")) {
                            sirihmerah();
                        } else if (nilai.equals("Bronkitis") || nilai.equals("bronkitis")) {
                            sirihmerah();
                        } else if (nilai.equals("Mata merah") || nilai.equals("mata merah")) {
                            sirihmerah();
                        } else if (nilai.equals("Diare") || nilai.equals("diare")) {
                            kunyit();
                            System.out.println("");
                            System.out.println("");
                            daunjambubiji();
                            System.out.println("");
                            System.out.println("");
                            kijibeling();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                            System.out.println("");
                            System.out.println("");
                            daunandong();
                        } else if (nilai.equals("Hepatitis") || nilai.equals("hepatitis")) {
                            daunmurbei();
                            System.out.println("");
                            System.out.println("");
                            sambiloto();
                            System.out.println("");
                            System.out.println("");
                            daunasam();
                            System.out.println("");
                            System.out.println("");
                            temulawak();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                            System.out.println("");
                            System.out.println("");
                            dauntempuyung();
                        } else if (nilai.equals("Radang") || nilai.equals("radang")) {
                            kunyit();
                            System.out.println("");
                            System.out.println("");
                            belimbingwuluh();
                        } else if (nilai.equals("Radang sendi") || nilai.equals("radang sendi")) {
                            temulawak();
                        } else if (nilai.equals("Rematik") || nilai.equals("rematik")) {
                            jahe();
                            System.out.println("");
                            System.out.println("");
                            daunbeluntas();
                            System.out.println("");
                            System.out.println("");
                            brotowali();
                            System.out.println("");
                            System.out.println("");
                            kayumanis();
                            System.out.println("");
                            System.out.println("");
                            akarwangi();
                        } else if (nilai.equals("Wasir") || nilai.equals("wasir")) {
                            lidahbuaya();
                            System.out.println("");
                            System.out.println("");
                            dauntempuyung();
                            System.out.println("");
                            System.out.println("");
                            daunandong();
                        } else if (nilai.equals("Anemia") || nilai.equals("anemia")) {
                            seledri();
                            System.out.println("");
                            System.out.println("");
                            daunkelor();
                        } else if (nilai.equals("Kanker") || nilai.equals("kanker")) {
                            jahe();
                            System.out.println("");
                            System.out.println("");
                            temulawak();
                            System.out.println("");
                            System.out.println("");
                            kijibeling();
                            System.out.println("");
                            System.out.println("");
                            dauncincau();
                            System.out.println("");
                            System.out.println("");
                            belimbingwuluh();
                            System.out.println("");
                            System.out.println("");
                            seledri();
                        } else if (nilai.equals("Jantung") || nilai.equals("jantung")) {
                            kayumanis();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                        } else if (nilai.equals("Stroke") || nilai.equals("stroke")) {
                            daunjinten();
                        } else if (nilai.equals("Demam") || nilai.equals("demam")) {
                            sambiloto();
                            System.out.println("");
                            System.out.println("");
                            pegagan();
                            System.out.println("");
                            System.out.println("");
                            dauncincau();
                            System.out.println("");
                            System.out.println("");
                            brotowali();
                            System.out.println("");
                            System.out.println("");
                            daunjinten();
                            System.out.println("");
                            System.out.println("");
                            daunkelor();
                            System.out.println("");
                            System.out.println("");
                            alangalang();
                            System.out.println("");
                            System.out.println("");
                            akarwangi();
                        } else if (nilai.equals("Keputihan") || nilai.equals("keputihan")) {
                            daunbeluntas();
                        } else if (nilai.equals("TBC") || nilai.equals("tbc")) {
                            daunbeluntas();
                        } else if (nilai.equals("Sakit gigi") || nilai.equals("sakit gigi")) {
                            sambiloto();
                        } else if (nilai.equals("Maag") || nilai.equals("maag")) {
                            kunyit();
                        } else if (nilai.equals("Kencing batu") || nilai.equals("kencing batu")) {
                            dauntempuyung();
                        } else if (nilai.equals("Asam urat") || nilai.equals("asam urat")) {
                            dauntempuyung();
                        } else if (nilai.equals("Radang gusi") || nilai.equals("radang gusi")) {
                            daunandong();
                        } else if (nilai.equals("Cacingan") || nilai.equals("cacingan")) {
                            daunkelor();
                            System.out.println("");
                            System.out.println("");
                            temugiring();
                        } else if (nilai.equals("Sakit perut") || nilai.equals("sakit perut")) {
                            dauncincau();
                            System.out.println("");
                            System.out.println("");
                            temugiring();
                        } else if (nilai.equals("Cacar air") || nilai.equals("cacar air")) {
                            temugiring();
                        } else if (nilai.equals("Bau mulut") || nilai.equals("bau mulut")) {
                            akarwangi();
                        } else if (nilai.equals("Batu ginjal") || nilai.equals("batu ginjal")) {
                            akarwangi();
                        } else {
                            System.out.println("TIDAK ADA DI DAFTAR PENCAHARIAN");
                        }
                    }
                    if (data == 3) {
                        String[] datatum= datatumbuhan;
                        System.out.println("Sorting berdasarkan abjad");
                        Bubblesort(datatum);
                            
                    }
                    System.out.println("");
                    //kode pengulangan ke halaman yang tadi
                    System.out.println("apakah anda ingin kembali lagi?y/n");
                    ulang = input.next();
                } while (ulang.equals("y") || ulang.equals("Y"));
                //kode pengulangan ke halaman home
                System.out.println("apakah anda mau kembali ke home?y/n");
                ulang2 = input.next();
            } while (ulang2.equals("y") || ulang2.equals("Y"));
            System.out.println(">>>>>>>>>>>>>>>TERIMA KASIH<<<<<<<<<<<<<<<");
            System.out.println("Semoga sehat selalu");
            System.out.println("Copyright Galuh Muhammad Iman Akbar");
        } catch (Exception e) {
            System.out.println("Masukan inputan dengan benar");
            System.out.println("");
            daftar();
        }
    }

    public static void main(String[] args) {
        Project_UAS2 oke= new Project_UAS2();
        try {
            oke.daftar();
        } catch (Exception e) {
            System.out.println("salah");

        }

    }
}
