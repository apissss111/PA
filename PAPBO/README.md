# Posttest 5 OOP - Abstract Class & Interface

## Deskripsi
Pada posttest ini, program dari pertemuan sebelumnya dikembangkan dengan mengubah class induk menjadi abstract class dan menambahkan interface.

Perubahan dilakukan tanpa mengubah alur utama program, jadi fitur yang sudah ada tetap berjalan seperti sebelumnya.

---

## Perubahan yang Dilakukan

### 1. Abstract Class
Class `Event` diubah menjadi abstract class.

Alasannya karena class ini hanya digunakan sebagai dasar (template) untuk class turunan seperti `EventVolunteer` dan `EventSponsor`, sehingga tidak perlu dibuat objek secara langsung.

Selain itu, ditambahkan abstract method:
- `getInfo()`

Method ini wajib diimplementasikan oleh semua class turunan agar setiap jenis event bisa memberikan informasi sesuai tipenya.

---

### 2. Interface
Ditambahkan interface baru bernama `EventAksi`.

Interface ini berisi 2 method:
- `tambahCatatan(String catatan)`
- `tampilAksi()`

Kedua method ini digunakan untuk menambahkan dan menampilkan catatan tambahan pada event.

---

### 3. Implementasi Interface
Class:
- `EventVolunteer`
- `EventSponsor`

menggunakan (`implements`) interface `EventAksi`.

Setiap class memiliki implementasi masing-masing untuk menyimpan dan menampilkan catatan sesuai kebutuhan.

---

## Hasil
Dengan perubahan ini:
- Struktur program jadi lebih jelas (class induk sebagai template)
- Setiap event punya identitas masing-masing lewat method `getInfo()`
- Fitur tambahan bisa ditambahkan lewat interface tanpa mengganggu class utama

---

## Catatan
Perubahan pada posttest ini hanya menambahkan konsep abstract class dan interface, sedangkan konsep sebelumnya seperti encapsulation, inheritance, dan polymorphism tetap digunakan.