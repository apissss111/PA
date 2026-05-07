import java.util.ArrayList;
import java.util.Scanner;

public class Admin extends User {

    Scanner input = new Scanner(System.in);

    public Admin(String username, String password) {
        super(username, password);
    }

    @Override
    public void menu(ArrayList<Booth> dataBooth,
                     ArrayList<Penyewaan> dataSewa) {

        int pilih;

        do {

            System.out.println("\n=== MENU ADMIN ===");
            System.out.println("1. Tambah Booth");
            System.out.println("2. Lihat Booth");
            System.out.println("3. Lihat Penyewaan");
            System.out.println("4. Kembali");
            System.out.print("Pilih : ");
            pilih = input.nextInt();
            input.nextLine();

            switch (pilih) {

                case 1:

                    System.out.print("Nama Booth : ");
                    String nama = input.nextLine();

                    System.out.print("Lokasi : ");
                    String lokasi = input.nextLine();

                    System.out.print("Harga : ");
                    double harga = input.nextDouble();

                    dataBooth.add(new Booth(nama, lokasi, harga));

                    System.out.println("Booth berhasil ditambah");
                    break;

                case 2:

                    for (int i = 0; i < dataBooth.size(); i++) {

                        System.out.println("\nBooth ke-" + (i + 1));
                        dataBooth.get(i).tampilBooth();
                    }

                    break;

                case 3:

                    for (int i = 0; i < dataSewa.size(); i++) {

                        System.out.println("\nData Penyewaan");
                        dataSewa.get(i).tampilPenyewaan();
                    }

                    break;

                case 4:
                    System.out.println("Kembali");
                    break;

                default:
                    System.out.println("Pilihan tidak ada");
            }

        } while (pilih != 4);

    }
}