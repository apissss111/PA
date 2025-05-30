#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // untuk format tabel
using namespace std;

const int MAX_FILM = 100;
const int MAX_USER = 100;
const int MAX_PESANAN = 100;

struct Film {
    string judul;
    string genre;
    int durasi; // menit
    string waktuPemutaran; // contoh: "15.00-16.30"
    string harga; // string, misal "Rp70000"
    bool tersedia;
    bool kursi[5][5]; // kursi 5x5, false = kosong, true = terisi
};

struct Pesanan {
    string username;
    string judulFilm;
    int jumlahTiket;
    string totalHarga;
    int kursiX[25]; // simpan koordinat kursi yang dipesan
    int kursiY[25];
};

string usernames[MAX_USER];
string passwords[MAX_USER];
int totalUser = 1; // sudah ada admin di index 0

Film daftarFilm[MAX_FILM];
int jumlahFilm = 0;

Pesanan daftarPesanan[MAX_PESANAN];
int jumlahPesanan = 0;

// Inisialisasi akun admin
void inisialisasiAkun() {
    usernames[0] = "admin";
    passwords[0] = "admin";
}

// Login user/admin
int login(string &username) {
    string password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    for (int i = 0; i < totalUser; i++) {
        if (usernames[i] == username && passwords[i] == password) {
            return i;
        }
    }
    cout << "Login gagal.\n";
    return -1;
}

// Buat akun baru
void buatAkun() {
    if (totalUser >= MAX_USER) {
        cout << "Maksimum akun tercapai.\n";
        return;
    }
    cout << "Masukkan username baru: ";
    cin >> usernames[totalUser];
    cout << "Masukkan password baru: ";
    cin >> passwords[totalUser];
    cout << "Akun berhasil dibuat!\n";
    totalUser++;
}

// Tambah film baru
void tambahFilm() {
    if (jumlahFilm >= MAX_FILM) {
        cout << "Kapasitas film penuh.\n";
        return;
    }

    cout << "Masukkan judul film: ";
    cin.ignore();
    getline(cin, daftarFilm[jumlahFilm].judul);

    cout << "Masukkan genre: ";
    getline(cin, daftarFilm[jumlahFilm].genre);

    while (true) {
        cout << "Masukkan durasi (menit): ";
        cin >> daftarFilm[jumlahFilm].durasi;
        if (cin.fail() || daftarFilm[jumlahFilm].durasi <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Ulangi.\n";
        } else {
            cin.ignore(1000, '\n');
            break;
        }
    }

    cout << "Masukkan waktu pemutaran (contoh 15.00-16.30): ";
    getline(cin, daftarFilm[jumlahFilm].waktuPemutaran);

    cout << "Masukkan harga tiket (contoh Rp70000): ";
    getline(cin, daftarFilm[jumlahFilm].harga);

    daftarFilm[jumlahFilm].tersedia = true;

    // Inisialisasi semua kursi kosong (false)
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            daftarFilm[jumlahFilm].kursi[i][j] = false;

    jumlahFilm++;
    cout << "Film berhasil ditambahkan.\n";
}

// Lihat daftar film (hanya yg tersedia)
void lihatFilm() {
    if (jumlahFilm == 0) {
        cout << "Belum ada film.\n";
        return;
    }

    cout << left
         << setw(4) << "No"
         << setw(20) << "Judul"
         << setw(15) << "Genre"
         << setw(15) << "Durasi(menit)"
         << setw(20) << "Waktu"
         << setw(10) << "Harga" << endl;

    cout << string(84, '-') << endl;

    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].tersedia) {
            cout << left
                 << setw(4) << i + 1
                 << setw(20) << daftarFilm[i].judul
                 << setw(15) << daftarFilm[i].genre
                 << setw(15) << daftarFilm[i].durasi
                 << setw(20) << daftarFilm[i].waktuPemutaran
                 << setw(10) << daftarFilm[i].harga << endl;
        }
    }
}

// Cari film berdasarkan judul (keyword)
void cariFilm() {
    string keyword;
    cout << "Masukkan judul yang ingin dicari: ";
    cin.ignore();
    getline(cin, keyword);
    bool ketemu = false;
    for (int i = 0; i < jumlahFilm; i++) {
        if (daftarFilm[i].tersedia && daftarFilm[i].judul.find(keyword) != string::npos) {
            cout << i + 1 << ". " << daftarFilm[i].judul << " | " << daftarFilm[i].genre
                 << " | " << daftarFilm[i].durasi << " menit | " << daftarFilm[i].waktuPemutaran
                 << " | " << daftarFilm[i].harga << endl;
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Film tidak ditemukan.\n";
}

// Hapus film (set tersedia=false)
void hapusFilm() {
    lihatFilm();
    int pilih;
    while (true) {
        cout << "Pilih nomor film yang akan dihapus: ";
        cin >> pilih;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Masukkan angka.\n";
        } else break;
    }

    if (pilih >= 1 && pilih <= jumlahFilm) {
        daftarFilm[pilih - 1].tersedia = false;
        cout << "Film berhasil dihapus.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

// Ubah durasi film
void ubahDurasiFilm() {
    lihatFilm();
    int pilih;
    cout << "Pilih nomor film yang ingin diubah durasinya: ";
    cin >> pilih;
    if (pilih >= 1 && pilih <= jumlahFilm && daftarFilm[pilih - 1].tersedia) {
        int durasiBaru;
        cout << "Masukkan durasi baru (menit): ";
        cin >> durasiBaru;
        daftarFilm[pilih - 1].durasi = durasiBaru;
        cout << "Durasi film berhasil diubah.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

// Ubah waktu pemutaran film
void ubahWaktuPemutaranFilm() {
    lihatFilm();
    int pilih;
    cout << "Pilih nomor film yang ingin diubah waktu pemutarannya: ";
    cin >> pilih;
    if (pilih >= 1 && pilih <= jumlahFilm && daftarFilm[pilih - 1].tersedia) {
        cin.ignore();
        string waktuBaru;
        cout << "Masukkan waktu pemutaran baru (contoh 15.00-16.30): ";
        getline(cin, waktuBaru);
        daftarFilm[pilih - 1].waktuPemutaran = waktuBaru;
        cout << "Waktu pemutaran film berhasil diubah.\n";
    } else {
        cout << "Pilihan tidak valid.\n";
    }
}

// Lihat daftar pesanan admin
void lihatPesanan() {
    if (jumlahPesanan == 0) {
        cout << "Belum ada pesanan.\n";
        return;
    }
    cout << left
         << setw(4) << "No"
         << setw(15) << "Username"
         << setw(20) << "Judul Film"
         << setw(12) << "Jumlah"
         << setw(20) << "Kursi"
         << setw(10) << "Total" << endl;
    cout << string(81, '-') << endl;

    for (int i = 0; i < jumlahPesanan; i++) {
        cout << left
             << setw(4) << i + 1
             << setw(15) << daftarPesanan[i].username
             << setw(20) << daftarPesanan[i].judulFilm
             << setw(12) << daftarPesanan[i].jumlahTiket;

        // Tampilkan kursi yg dipesan (format A1, B3, dst)
        for (int k = 0; k < daftarPesanan[i].jumlahTiket; k++) {
            char rowChar = 'A' + daftarPesanan[i].kursiX[k];
            int colNum = daftarPesanan[i].kursiY[k] + 1;
            cout << rowChar << colNum;
            if (k < daftarPesanan[i].jumlahTiket - 1) cout << ", ";
        }
        cout << setw(10) << "" << daftarPesanan[i].totalHarga << endl;
    }
}

// Tampilkan layout kursi untuk film tertentu
void tampilkanKursi(Film &film) {
    cout << "\nLayout kursi (X = sudah dipesan, O = tersedia):\n";
    cout << "   1 2 3 4 5\n";
    for (int i = 0; i < 5; i++) {
        cout << char('A' + i) << "  ";
        for (int j = 0; j < 5; j++) {
            if (film.kursi[i][j]) cout << "X ";
            else cout << "O ";
        }
        cout << endl;
    }
}

// Fungsi untuk memesan tiket dan pilih kursi
void pesanTiket(string user) {
    lihatFilm();
    if (jumlahFilm == 0) return;

    int pilih;
    while (true) {
        cout << "Pilih nomor film: ";
        cin >> pilih;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid. Masukkan angka.\n";
        } else break;
    }

    if (pilih < 1 || pilih > jumlahFilm || !daftarFilm[pilih - 1].tersedia) {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    Film &film = daftarFilm[pilih - 1];

    int jumlah;
    while (true) {
        cout << "Jumlah tiket: ";
        cin >> jumlah;
        if (cin.fail() || jumlah <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Jumlah tidak valid. Harus lebih dari 0.\n";
        } else if (jumlah > 25) {
            cout << "Maksimal pembelian 25 tiket.\n";
        } else {
            break;
        }
    }

    // Tampilkan layout kursi
    tampilkanKursi(film);

    int kursiTerpilihX[25], kursiTerpilihY[25];
    int count = 0;
    while (count < jumlah) {
        string kursiInput;
        cout << "Pilih kursi ke-" << count + 1 << " (format A1 - E5): ";
        cin >> kursiInput;

        if (kursiInput.length() < 2 || kursiInput.length() > 3) {
            cout << "Format kursi salah.\n";
            continue;
        }

        char rowChar = toupper(kursiInput[0]);
        int row = rowChar - 'A';
        int col;

        try {
            col = stoi(kursiInput.substr(1)) - 1;
        } catch (...) {
            cout << "Nomor kursi tidak valid.\n";
            continue;
        }

        if (row < 0 || row >= 5 || col < 0 || col >= 5) {
            cout << "Kursi di luar jangkauan.\n";
            continue;
        }

        if (film.kursi[row][col]) {
            cout << "Kursi sudah dipesan, pilih yang lain.\n";
            continue;
        }

        // Cek kursi sudah dipilih sebelumnya dalam sesi ini
        bool sudahDipilih = false;
        for (int k = 0; k < count; k++) {
            if (kursiTerpilihX[k] == row && kursiTerpilihY[k] == col) {
                sudahDipilih = true;
                break;
            }
        }
        if (sudahDipilih) {
            cout << "Kursi sudah dipilih sebelumnya.\n";
            continue;
        }

        kursiTerpilihX[count] = row;
        kursiTerpilihY[count] = col;
        count++;
    }

    // Tandai kursi sebagai terisi
    for (int i = 0; i < jumlah; i++) {
        film.kursi[kursiTerpilihX[i]][kursiTerpilihY[i]] = true;
    }

    // Hitung total harga
    string hargaStr = film.harga;
    string angkaHarga = "";
    for (char c : hargaStr) {
        if (isdigit(c)) angkaHarga += c;
    }
    int hargaInt = 0;
    if (!angkaHarga.empty()) hargaInt = stoi(angkaHarga);

    int totalInt = hargaInt * jumlah;
    stringstream ss;
    ss << "Rp" << totalInt;

    // Simpan pesanan
    daftarPesanan[jumlahPesanan].username = user;
    daftarPesanan[jumlahPesanan].judulFilm = film.judul;
    daftarPesanan[jumlahPesanan].jumlahTiket = jumlah;
    daftarPesanan[jumlahPesanan].totalHarga = ss.str();
    for (int i = 0; i < jumlah; i++) {
        daftarPesanan[jumlahPesanan].kursiX[i] = kursiTerpilihX[i];
        daftarPesanan[jumlahPesanan].kursiY[i] = kursiTerpilihY[i];
    }
    jumlahPesanan++;

    cout << "Tiket berhasil dipesan!\n";
}

// Tampilkan riwayat tiket untuk user tertentu
void riwayatTiket(string user) {
    bool ada = false;
    cout << "Riwayat tiket untuk user: " << user << endl;
    for (int i = 0; i < jumlahPesanan; i++) {
        if (daftarPesanan[i].username == user) {
            ada = true;
            cout << "Film: " << daftarPesanan[i].judulFilm
                 << ", Jumlah tiket: " << daftarPesanan[i].jumlahTiket
                 << ", Kursi: ";
            for (int k = 0; k < daftarPesanan[i].jumlahTiket; k++) {
                char rowChar = 'A' + daftarPesanan[i].kursiX[k];
                int colNum = daftarPesanan[i].kursiY[k] + 1;
                cout << rowChar << colNum;
                if (k < daftarPesanan[i].jumlahTiket - 1) cout << ", ";
            }
            cout << ", Total harga: " << daftarPesanan[i].totalHarga << endl;
        }
    }
    if (!ada) cout << "Belum ada riwayat tiket.\n";
}

void menuAdmin();
void menuUser(string username);

void menuAdmin() {
    int pilihan;
    do {
        cout << "\n=== Menu Admin ===\n";
        cout << "1. Lihat daftar film\n";
        cout << "2. Tambah film\n";
        cout << "3. Hapus film\n";
        cout << "4. Ubah durasi film\n";
        cout << "5. Ubah waktu pemutaran film\n";
        cout << "6. Lihat daftar pesanan\n";
        cout << "7. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: lihatFilm(); break;
            case 2: tambahFilm(); break;
            case 3: hapusFilm(); break;
            case 4: ubahDurasiFilm(); break;
            case 5: ubahWaktuPemutaranFilm(); break;
            case 6: lihatPesanan(); break;
            case 7: cout << "Logout...\n"; break;
            default: cout << "Pilihan salah.\n"; break;
        }
    } while (pilihan != 7);
}

void menuUser(string username) {
    int pilihan;
    do {
        cout << "\n=== Menu User ===\n";
        cout << "1. Lihat daftar film\n";
        cout << "2. Cari film\n";
        cout << "3. Pesan tiket\n";
        cout << "4. Riwayat tiket\n";
        cout << "5. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: lihatFilm(); break;
            case 2: cariFilm(); break;
            case 3: pesanTiket(username); break;
            case 4: riwayatTiket(username); break;
            case 5: cout << "Logout...\n"; break;
            default: cout << "Pilihan salah.\n"; break;
        }
    } while (pilihan != 5);
}

int main() {
    inisialisasiAkun();

    int pilihanUtama;
    do {
        cout << "\n=== Sistem Manajemen Tiket Bioskop ===\n";
        cout << "1. Login\n";
        cout << "2. Buat akun baru\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihanUtama;

        if (pilihanUtama == 1) {
            string username;
            int idx = login(username);
            if (idx != -1) {
                if (username == "admin") {
                    menuAdmin();
                } else {
                    menuUser(username);
                }
            }
        } else if (pilihanUtama == 2) {
            buatAkun();
        } else if (pilihanUtama == 3) {
            cout << "Terima kasih telah menggunakan layanan bioskop KHASIHANCUR.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihanUtama != 3);

    return 0;
}
