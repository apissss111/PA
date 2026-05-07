import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static Scanner input = new Scanner(System.in);

    static ArrayList<Booth> dataBooth = new ArrayList<>();
    static ArrayList<Penyewaan> dataSewa = new ArrayList<>();

    public static void main(String[] args) {

        Admin admin = new Admin("admin", "123");

        dataBooth.add(new Booth("Booth Makanan", "A1", 500000));
        dataBooth.add(new Booth("Booth Minuman", "B1", 400000));

        int pilih;

        do {

            System.out.println("\n=== SISTEM PENYEWAAN BOOTH RAMADHAN ===");
            System.out.println("1. Login Admin");
            System.out.println("2. Login Pelanggan");
            System.out.println("3. Keluar");
            System.out.print("Pilih : ");
            pilih = input.nextInt();
            input.nextLine();

            switch (pilih) {

                case 1:

                    System.out.print("Username : ");
                    String userAdmin = input.nextLine();

                    System.out.print("Password : ");
                    String passAdmin = input.nextLine();

                    if (userAdmin.equals("admin") && passAdmin.equals("123")) {
                        admin.menu(dataBooth, dataSewa);
                    } else {
                        System.out.println("Login gagal!");
                    }

                    break;

                case 2:

                    System.out.print("Nama pelanggan : ");
                    String nama = input.nextLine();

                    Pelanggan pelanggan = new Pelanggan(nama, "123");

                    pelanggan.menu(dataBooth, dataSewa);

                    break;

                case 3:
                    System.out.println("Program selesai");
                    break;

                default:
                    System.out.println("Pilihan tidak ada");
            }

        } while (pilih != 3);

    }
}