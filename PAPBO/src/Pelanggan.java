import java.util.ArrayList;
import java.util.Scanner;

public class Pelanggan extends User {

    Scanner input = new Scanner(System.in);

    public Pelanggan(String username, String password) {
        super(username, password);
    }

    @Override
    public void menu(ArrayList<Booth> dataBooth,
                     ArrayList<Penyewaan> dataSewa) {

        int pilih;

        do {

            System.out.println("\n=== MENU PELANGGAN ===");
            System.out.println("1. Lihat Booth");
            System.out.println("2. Sewa Booth");
            System.out.println("3. Kembali");
            System.out.print("Pilih : ");
            pilih = input.nextInt();

            switch (pilih) {

                case 1:

                    for (int i = 0; i < dataBooth.size(); i++) {

                        System.out.println("\nBooth ke-" + (i + 1));
                        dataBooth.get(i).tampilBooth();
                    }

                    break;

                case 2:

                    for (int i = 0; i < dataBooth.size(); i++) {

                        System.out.println((i + 1) + ". "
                                + dataBooth.get(i).getNamaBooth());
                    }

                    System.out.print("Pilih booth : ");
                    int index = input.nextInt() - 1;

                    System.out.print("Lama sewa (hari) : ");
                    int hari = input.nextInt();

                    Penyewaan sewa =
                            new Penyewaan(this,
                                    dataBooth.get(index),
                                    hari);

                    dataSewa.add(sewa);

                    dataBooth.get(index).setTersedia(false);

                    System.out.println("Booth berhasil disewa");

                    break;

                case 3:
                    System.out.println("Kembali");
                    break;

                default:
                    System.out.println("Pilihan tidak ada");
            }

        } while (pilih != 3);

    }
}