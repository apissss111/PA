package com.boothramadhan.model;

public class Penyewaan {

    private String namaPelanggan;
    private String namaBooth;
    private int lamaSewa;
    private double totalHarga;

    public Penyewaan(String namaPelanggan,
                      String namaBooth,
                      int lamaSewa,
                      double totalHarga) {

        this.namaPelanggan = namaPelanggan;
        this.namaBooth = namaBooth;
        this.lamaSewa = lamaSewa;
        this.totalHarga = totalHarga;
    }

    public String getNamaPelanggan() {
        return namaPelanggan;
    }
    public String getNamaBooth() {
        return namaBooth;
    }

    public int getLamaSewa() {
        return lamaSewa;
    }

    public double getTotalHarga() {
        return totalHarga;
    }
}