public class Booth {

    private String namaBooth;
    private String lokasi;
    private double harga;
    private boolean tersedia;

    public Booth(String namaBooth, String lokasi, double harga) {

        this.namaBooth = namaBooth;
        this.lokasi = lokasi;
        this.harga = harga;
        this.tersedia = true;
    }

    public String getNamaBooth() {
        return namaBooth;
    }

    public double getHarga() {
        return harga;
    }

    public boolean isTersedia() {
        return tersedia;
    }

    public void setTersedia(boolean tersedia) {
        this.tersedia = tersedia;
    }

    public void tampilBooth() {

        System.out.println("Nama Booth : " + namaBooth);
        System.out.println("Lokasi : " + lokasi);
        System.out.println("Harga : " + harga);
        System.out.println("Tersedia : " + tersedia);
    }
}