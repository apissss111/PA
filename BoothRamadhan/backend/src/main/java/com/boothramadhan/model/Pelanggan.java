package com.boothramadhan.model;

public class Pelanggan extends User {

    public Pelanggan(String username, String password) {
        super(username, password);
    }

    @Override
    public String role() {
        return "Pelanggan";
    }
}