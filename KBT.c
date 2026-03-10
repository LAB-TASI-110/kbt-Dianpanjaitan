#include <stdio.h>
#include <string.h> // Untuk strlen dan strcmp

// Struktur untuk menyimpan data rute
typedef struct {
    char nama_rute[50];
    int harga;
} Rute;

// Fungsi untuk membersihkan buffer input setelah scanf untuk integer
void clearInputBuffer() {
    scanf("%*[^\n]"); // Baca dan buang semua karakter sampai newline
    scanf("%*c");     // Baca dan buang karakter newline itu sendiri
}

int main() {
    // Definisi rute dan harga
    Rute daftar_rute[] = {
        {"Medan - Siantar", 35000},
        {"Medan - Parapat", 50000},
        {"Medan - Porsea", 55000},
        {"Medan - Balige", 60000},
        {"Medan - Siborongborong", 65000},
        {"Medan - Muara", 70000},
        {"Medan - Tarutung", 75000},
        {"Medan - Pahae", 85000},
        {"Medan - Sipirok", 120000},
        {"Medan - Padang Sidempuan", 140000},
        {"Balige - Siantar", 50000}
    };
    int jumlah_rute = sizeof(daftar_rute) / sizeof(daftar_rute[0]);

    int pilihan_mobil;
    int harga_mobil = 0;
    char jenis_mobil[20];
    int pilihan_rute_idx;
    int jumlah_tiket;
    int harga_tiket_rute = 0;
    long long total_bayar = 0; // Menggunakan long long untuk total bayar jika nilai bisa besar

    printf("Selamat datang di Sistem Tiket Koperasi Bintang Tapanuli\n");
    printf("=========================================================\n");

    // Pemilihan Jenis Mobil
    printf("Pilih Jenis Mobil:\n");
    printf("1. Mobil Biasa (Rp100.000)\n");
    printf("2. Mobil Eksekutif (Rp160.000)\n");
    printf("Masukkan pilihan Anda (1/2): ");
    while (scanf("%d", &pilihan_mobil) != 1 || (pilihan_mobil < 1 || pilihan_mobil > 2)) {
        printf("Input tidak valid. Mohon masukkan 1 atau 2: ");
        clearInputBuffer(); // Bersihkan buffer input
    }
    clearInputBuffer(); // Bersihkan buffer input setelah input valid

    if (pilihan_mobil == 1) {
        harga_mobil = 100000;
        strcpy(jenis_mobil, "Biasa");
    } else {
        harga_mobil = 160000;
        strcpy(jenis_mobil, "Eksekutif");
    }

    // Pemilihan Rute
    printf("\nPilih Rute Perjalanan:\n");
    for (int i = 0; i < jumlah_rute; i++) {
        printf("%d. %s (Rp%d)\n", i + 1, daftar_rute[i].nama_rute, daftar_rute[i].harga);
    }
    printf("Masukkan pilihan Anda (1-%d): ", jumlah_rute);
    while (scanf("%d", &pilihan_rute_idx) != 1 || (pilihan_rute_idx < 1 || pilihan_rute_idx > jumlah_rute)) {
        printf("Input tidak valid. Mohon masukkan angka antara 1 dan %d: ", jumlah_rute);
        clearInputBuffer(); // Bersihkan buffer input
    }
    clearInputBuffer(); // Bersihkan buffer input setelah input valid
    
    pilihan_rute_idx--; // Sesuaikan dengan indeks array (0-based)
    harga_tiket_rute = daftar_rute[pilihan_rute_idx].harga;

    // Input Jumlah Tiket
    printf("\nMasukkan Jumlah Tiket yang ingin dibeli: ");
    while (scanf("%d", &jumlah_tiket) != 1 || jumlah_tiket <= 0) {
        printf("Input tidak valid. Mohon masukkan bilangan bulat positif untuk jumlah tiket: ");
        clearInputBuffer(); // Bersihkan buffer input
    }
    clearInputBuffer(); // Bersihkan buffer input setelah input valid

    // Kalkulasi Total Bayar
    total_bayar = (long long)harga_mobil + ((long long)harga_tiket_rute * jumlah_tiket);

    // Tampilkan Rincian Transaksi
    printf("\n=========================================================\n");
    printf("                 RINCIAN TRANSAKSI\n");
    printf("=========================================================\n");
    printf("Jenis Mobil         : %s\n", jenis_mobil);
    printf("Harga Mobil         : Rp%d\n", harga_mobil);
    printf("Rute Perjalanan     : %s\n", daftar_rute[pilihan_rute_idx].nama_rute);
    printf("Harga Tiket per Rute: Rp%d\n", harga_tiket_rute);
    printf("Jumlah Tiket        : %d\n", jumlah_tiket);
    printf("---------------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN    : Rp%lld\n", total_bayar);
    printf("=========================================================\n");

    return 0;
}
