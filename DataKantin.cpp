// Tugas Besar SI Rekap Kantin Tanpa Inputan
//Nama   : Reno Budiman
//NPM    : 4524210124
//Prodi  : Teknik Informatika
//Materi : Selection-Repetition-Array-Function-Pointer-Sort


#include <iostream>
#include <iomanip> // Untuk format tampilan tabel
#include <string> // untuk men deklarasi variabel tipe data string 
using namespace std;

// Function: Menampilkan informasi menu kantin
// Function ini digunakan untuk menampilkan data nama menu, harga, nama kantin, dan jam operasional
void tampilkanMenu(string* namaMenu, int* hargaMenu, int size, string namaKantin, string jamBuka, string jamTutup) { // untuk memanggil array string yang menyimpan daftar nama menu atau harga menu
    cout << "==============================================" << endl;
    cout << "            INFORMASI KANTIN                  " << endl;
    cout << "==============================================" << endl;
    cout << "Nama Kantin     : " << namaKantin << endl;
    cout << "Jam Operasional : " << jamBuka << " - " << jamTutup << endl;
    cout << "==============================================" << endl;

    cout << setw(15) << left << "Menu" << setw(10) << "Harga" << endl;
    cout << "----------------------------------------------" << endl;

    // Repetition: Loop untuk menampilkan menu
    for (int i = 0; i < size; i++) {
        cout << setw(15) << left << namaMenu[i] << "Rp " << setw(7) << right << hargaMenu[i] << endl;
    }

    cout << "==============================================" << endl;
}

// Function: Mengurutkan menu berdasarkan harga (Ascending)
// Sort (Insertion Sort) untuk mengurutkan harga menu dari terkecil ke terbesar // (void)fungsi yang tidak mengembalikan nilai apa pun kepada pemanggilnya
void insertionSort(string* namaMenu, int* hargaMenu, int size) { //pointer
    for (int i = 1; i < size; i++) {
        int keyHarga = hargaMenu[i]; // Pointer: Menyimpan nilai harga sementara // fungsi pointer menyimpan alamat memori dari variabel lain. Pointer sangat berguna untuk mengakses dan memanipulasi data dalam memori secara langsung
        string keyNama = namaMenu[i]; // Pointer: Menyimpan nama menu sementara
        int j = i - 1;

        // Selection: Memilih elemen yang lebih besar dari keyHarga untuk dipindahkan
        while (j >= 0 && hargaMenu[j] > keyHarga) { // ubah > ke < untuk mengubah asc - desc;
            hargaMenu[j + 1] = hargaMenu[j];
            namaMenu[j + 1] = namaMenu[j];
            j--;
        }
        hargaMenu[j + 1] = keyHarga; // Logika: Menempatkan keyHarga pada posisi yang benar
        namaMenu[j + 1] = keyNama; // Logika: Menempatkan keyNama pada posisi yang benar
    }
}

// Function: Menampilkan menu dengan harga termahal
// Function ini digunakan untuk mencari dan menampilkan menu dengan harga paling tinggi
void tampilkanMenuTermahal(string* namaMenu, int* hargaMenu, int size) {
    int maxIndex = 0; // Pointer: Menyimpan indeks harga maksimum

    // Repetition: Loop untuk mencari harga maksimum
    for (int i = 1; i < size; i++) {
        // Selection: Memilih elemen dengan harga lebih besar dari elemen sebelumnya
        if (hargaMenu[i] > hargaMenu[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << "==============================================" << endl;
    cout << "            INFORMASI MENU TERMAHAL           " << endl;
    cout << "==============================================" << endl;
    cout << "Menu           : " << namaMenu[maxIndex] << endl;
    cout << "Harga          : Rp " << hargaMenu[maxIndex] << endl;
    cout << "==============================================" << endl;
}

int main() {
    // Array1: Menyimpan data menu dan harga
    const int size = 5;
    string namaMenuReno[size] = {"Nasi Goreng", "Mie Ayam", "Es Teh", "Bakso", "Kerupuk"};
    int hargaMenuReno[size] = {15000, 12000, 5000, 18000, 2000};

    // Variabel informasi kantin
    string namaKantin = "KANTIN SMAN1 TANGSEL";
    string jamBuka = "08:00";
    string jamTutup = "16:00";

    // Tampilkan menu sebelum sorting
    cout << "=== Data Sebelum Sorting ===" << endl;
    tampilkanMenu(namaMenuReno, hargaMenuReno, size, namaKantin, jamBuka, jamTutup);

    // Sort menu berdasarkan harga
    insertionSort(namaMenuReno, hargaMenuReno, size);

    // Tampilkan menu setelah sorting
    cout << "\n=== Data Setelah Sorting ===" << endl;
    tampilkanMenu(namaMenuReno, hargaMenuReno, size, namaKantin, jamBuka, jamTutup);

    // Tampilkan menu termahal
    cout << "\n=== Informasi Menu Termahal ===" << endl;
    tampilkanMenuTermahal(namaMenuReno, hargaMenuReno, size);

    cin.get();
}
