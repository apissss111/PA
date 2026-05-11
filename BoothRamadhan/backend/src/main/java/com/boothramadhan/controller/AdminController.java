package com.boothramadhan.controller;

import com.boothramadhan.model.Booth;
import com.boothramadhan.model.Penyewaan;
import com.boothramadhan.service.DataService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;

@RestController
@RequestMapping("/admin")
@CrossOrigin
public class AdminController {

    @Autowired
    private DataService dataService;

    @GetMapping("/booth")
    public ArrayList<Booth> lihatBooth() {
        return dataService.getDataBooth();
    }

     @PostMapping("/tambah")
    public String tambahBooth(@RequestBody Booth booth) {

        dataService.tambahBooth(booth);

        return "Booth berhasil ditambah";
    }

    @GetMapping("/penyewaan")
    public ArrayList<Penyewaan> lihatPenyewaan() {
        return dataService.getDataSewa();
    }
}