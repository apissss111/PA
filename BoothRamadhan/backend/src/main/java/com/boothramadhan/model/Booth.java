package com.boothramadhan.model;

public class Booth {

    private int id;
    private String namaBooth;
    private String lokasi;
    private double harga;
    private boolean tersedia;

    public Booth(int id, String namaBooth, String lokasi, double harga) {
        this.id = id;
        this.namaBooth = namaBooth;
        this.lokasi = lokasi;
        this.harga = harga;
        this.tersedia = true;
    }

    public int getId() {
        return id;
    }

    public String getNamaBooth() {
        return namaBooth;
    }
    public String getLokasi() {
        return lokasi;
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
}