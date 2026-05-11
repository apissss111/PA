package com.boothramadhan.controller;

import com.boothramadhan.model.Booth;
import com.boothramadhan.model.Penyewaan;
import com.boothramadhan.service.DataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;

@RestController
@RequestMapping("/pelanggan")
@CrossOrigin
public class PelangganController {

    @Autowired
    private DataService dataService;

    @GetMapping("/booth")
    public ArrayList<Booth> lihatBooth() {
        return dataService.getDataBooth();
    }
    @PostMapping("/sewa")
    public String sewaBooth(@RequestBody Penyewaan penyewaan) {

        dataService.tambahPenyewaan(penyewaan);

        return "Booth berhasil disewa";
    }
}
