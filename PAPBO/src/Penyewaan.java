public class Penyewaan {

    private Pelanggan pelanggan;
    private Booth booth;
    private int lamaSewa;
    private double totalHarga;

    public Penyewaan(Pelanggan pelanggan,
                     Booth booth,
                     int lamaSewa) {

        this.pelanggan = pelanggan;
        this.booth = booth;
        this.lamaSewa = lamaSewa;

        totalHarga = booth.getHarga() * lamaSewa;
    }

    public void tampilPenyewaan() {

        System.out.println("Nama Pelanggan : "
                + pelanggan.username);

        System.out.println("Booth : "
                + booth.getNamaBooth());

        System.out.println("Lama Sewa : "
                + lamaSewa + " hari");

        System.out.println("Total Harga : "
                + totalHarga);
    }
}