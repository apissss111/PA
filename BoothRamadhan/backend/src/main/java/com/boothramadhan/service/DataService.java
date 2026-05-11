package com.boothramadhan.service;

import com.boothramadhan.model.Booth;
import com.boothramadhan.model.Penyewaan;
import org.springframework.stereotype.Service;

import java.util.ArrayList;

@Service
public class DataService {

    private ArrayList<Booth> dataBooth = new ArrayList<>();
    private ArrayList<Penyewaan> dataSewa = new ArrayList<>();

    public DataService() {

        dataBooth.add(new Booth(1, "Booth Makanan", "A1", 500000));
        dataBooth.add(new Booth(2, "Booth Minuman", "B2", 350000));
    }

    public ArrayList<Booth> getDataBooth() {
        return dataBooth;
    }
public ArrayList<Penyewaan> getDataSewa() {
        return dataSewa;
    }

    public void tambahBooth(Booth booth) {
        dataBooth.add(booth);
    }

    public void tambahPenyewaan(Penyewaan penyewaan) {
        dataSewa.add(penyewaan);
    }
}