// NAMA  : MUHAMMAD ALFAROBI
// NIM   : 23343011
// KASUS : MANAJEMEN LAUNDRY

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAX_PELANGGAN = 50;
const int MAX_PESANAN = 150;

struct Pelanggan {
    string nama;
    string alamat;
    string telepon;
    int idPelanggan;
};

struct Pesanan {
    int idPelanggan;
    string jenisCucian;
    int jumlah;
    double berat;
    double totalBiaya;
    bool selesai;
};

vector<Pelanggan> dataPelanggan;
vector<Pesanan> dataPesanan;

int idPelangganCounter = 1;

void inputPelanggan() {
    Pelanggan pelanggan;
    cout << "Masukkan nama pelanggan: ";
    getline(cin, pelanggan.nama);
    cout << "Masukkan alamat pelanggan: ";
    getline(cin, pelanggan.alamat);
    cout << "Masukkan nomor telepon pelanggan: ";
    getline(cin, pelanggan.telepon);
    pelanggan.idPelanggan = idPelangganCounter++;
    dataPelanggan.push_back(pelanggan);
    cout << "Data pelanggan berhasil ditambahkan. ID pelanggan: " << pelanggan.idPelanggan << endl << endl;
}

void pesananLaundry() {
    cout << "Masukkan ID pelanggan: ";
    int idPelanggan;
    cin >> idPelanggan;

    Pelanggan pelanggan;
    bool foundPelanggan = false;
    for (const Pelanggan& p : dataPelanggan) {
        if (p.idPelanggan == idPelanggan) {
            pelanggan = p;
            foundPelanggan = true;
            break;
        }
    }

    if (!foundPelanggan) {
        cout << "Pelanggan dengan ID " << idPelanggan << " tidak ditemukan." << endl << endl;
        return;
    }

    cout << "\nData Pelanggan:" << endl;
    cout << "ID Pelanggan: " << pelanggan.idPelanggan << endl;
    cout << "Nama: " << pelanggan.nama << endl;
    cout << "Alamat: " << pelanggan.alamat << endl;
    cout << "Nomor Telepon: " << pelanggan.telepon << endl;

    Pesanan pesanan;
    pesanan.idPelanggan = idPelanggan;

    cout << "\nPilih jenis cucian (1. Pakaian, 2. Selimut, 3. Sarung): ";
    int jenis;
    cin >> jenis;

    switch (jenis) {
        case 1:
            pesanan.jenisCucian = "Pakaian";
            break;
        case 2:
            pesanan.jenisCucian = "Selimut";
            break;
        case 3:
            pesanan.jenisCucian = "Sarung";
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return;
    }

    cout << "Masukkan jumlah cucian: ";
    int jumlah;
    cin >> jumlah;
    pesanan.jumlah = jumlah;

    cout << "Masukkan berat cucian (kg): ";
    int berat;
    cin >> berat;
    pesanan.berat = berat;

    switch (jenis) {
        case 1:
            pesanan.totalBiaya = jumlah * 4000.0;
            break;
        case 2:
            pesanan.totalBiaya = jumlah * 5000.0;
            break;
        case 3:
            pesanan.totalBiaya = jumlah * 3000.0;
            break;
    }

    dataPesanan.push_back(pesanan);
    cout << "Pesanan berhasil ditambahkan. Total Biaya: Rp " << fixed << setprecision(0) << pesanan.totalBiaya << endl << endl;
}

void tampilkanPesananBelumSelesai() {
    cout << "\nDaftar pesanan belum selesai:" << endl;
    for (const Pesanan& pesanan : dataPesanan) {
        if (!pesanan.selesai) {
            cout << "ID Pelanggan: " << pesanan.idPelanggan << " | Jenis Cucian: " << pesanan.jenisCucian
                 << " | Jumlah Cucian: " << pesanan.jumlah << " | Berat: " << pesanan.berat
                 << " kg | Total Biaya: Rp " << fixed << setprecision(0) << pesanan.totalBiaya << endl;
        }
    }
    cout << endl;
}

void tandaiSelesai() {
    cout << "Masukkan ID pelanggan yang pesanannya sudah selesai: ";
    int idPelanggan;
    cin >> idPelanggan;

    cout << "\nPesanan yang sudah selesai untuk ID Pelanggan " << idPelanggan << ":" << endl;
    for (Pesanan& pesanan : dataPesanan) {
        if (pesanan.idPelanggan == idPelanggan && !pesanan.selesai) {
            pesanan.selesai = true;
            cout << "Jenis Cucian: " << pesanan.jenisCucian << " | Jumlah Cucian: " << pesanan.jumlah
                 << " | Berat: " << pesanan.berat << " kg | Total Biaya: Rp " << fixed << setprecision(0) << pesanan.totalBiaya << endl;
            cout << "Pesanan sudah selesai." << endl << endl;
            return;
        }
    }

    cout << "Pesanan tidak ditemukan atau sudah selesai." << endl << endl;
}

void tampilkanRiwayatPesanan() {
    cout << "\nRiwayat Pesanan Selesai:" << endl;
    for (const Pesanan& pesanan : dataPesanan) {
        if (pesanan.selesai) {
            cout << "ID Pelanggan: " << pesanan.idPelanggan << " | Jenis Cucian: " << pesanan.jenisCucian
                 << " | Jumlah Cucian: " << pesanan.jumlah << " | Berat: " << pesanan.berat
                 << " kg | Total Biaya: Rp " << fixed << setprecision(0) << pesanan.totalBiaya << endl;
        }
    }
    cout << endl;
}

void cariDataPelanggan() {
    cout << "Masukkan ID pelanggan yang ingin dicari: ";
    int idPelanggan;
    cin >> idPelanggan;

    cout << "\nData Pelanggan untuk ID Pelanggan " << idPelanggan << ":" << endl;
    for (const Pelanggan& pelanggan : dataPelanggan) {
        if (pelanggan.idPelanggan == idPelanggan) {
            cout << "ID Pelanggan: " << pelanggan.idPelanggan << endl;
            cout << "Nama: " << pelanggan.nama << endl;
            cout << "Alamat: " << pelanggan.alamat << endl;
            cout << "Nomor Telepon: " << pelanggan.telepon << endl << endl;
            return;
        }
    }

    cout << "ID Pelanggan tidak ditemukan." << endl << endl;
}

int main() {
    cout << "Selamat datang di Laundry KiLOAN" << endl;

    int pilihan;
    do {
        cout << "Menu Laundry:" << endl;
        cout << "1. Input data pelanggan" << endl;
        cout << "2. Pemesanan layanan laundry" << endl;
        cout << "3. Menampilkan daftar pesanan yang belum selesai" << endl;
        cout << "4. Menandai pesanan sudah selesai" << endl;
        cout << "5. Menampilkan riwayat pesanan yang sudah selesai" << endl;
        cout << "6. Cari data pelanggan berdasarkan ID" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih menu (1-7): ";
        cin >> pilihan;
        cin.ignore();  // Menangani karakter newline (\n) yang tersisa di buffer

        cout << endl;

        switch (pilihan) {
            case 1:
                inputPelanggan();
                break;
            case 2:
                pesananLaundry();
                break;
            case 3:
                tampilkanPesananBelumSelesai();
                break;
            case 4:
                tandaiSelesai();
                break;
            case 5:
                tampilkanRiwayatPesanan();
                break;
            case 6:
                cariDataPelanggan();
                break;
            case 7:
                cout << "Terima kasih sudah menggunakan jasa laundry kami !" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
