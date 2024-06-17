#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur DataMahasiswa
typedef struct {
    int id;
    char nama[50];
    char tempatTanggalLahir[50];
    float ipk;
} DataMahasiswa;

// Fungsi untuk menambahkan data mahasiswa
void tambahDataMahasiswa(DataMahasiswa *list, int *jumlah, int id, char *nama, char *ttl, float ipk) {
    list[*jumlah].id = id;
    strcpy(list[*jumlah].nama, nama);
    strcpy(list[*jumlah].tempatTanggalLahir, ttl);
    list[*jumlah].ipk = ipk;
    (*jumlah)++;
}

// Fungsi pencarian sequential search
DataMahasiswa* cariSequential(DataMahasiswa *list, int jumlah, int id) {
    for (int i = 0; i < jumlah; i++) {
        if (list[i].id == id) {
            return &list[i];
        }
    }
    return NULL;
}

// Fungsi untuk membandingkan dua mahasiswa berdasarkan id
int bandingkan(const void *a, const void *b) {
    return ((DataMahasiswa*)a)->id - ((DataMahasiswa*)b)->id;
}

// Fungsi pencarian binary search
DataMahasiswa* cariBinary(DataMahasiswa *list, int jumlah, int id) {
    int kiri = 0;
    int kanan = jumlah - 1;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (list[tengah].id == id) {
            return &list[tengah];
        } else if (list[tengah].id < id) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return NULL;
}

// Fungsi untuk mencetak data mahasiswa
void cetakDataMahasiswa(DataMahasiswa *mhs) {
    if (mhs != NULL) {
        printf("NIM: %d\n", mhs->id);
        printf("Nama: %s\n", mhs->nama);
        printf("TTL: %s\n", mhs->tempatTanggalLahir);
        printf("IPK: %.2f\n", mhs->ipk);
    } else {
        printf("Mahasiswa tidak ditemukan.\n");
    }
}

int main() {
    DataMahasiswa listMahasiswa[100];
    int jumlah = 0;

    // Menambahkan data mahasiswa
    tambahDataMahasiswa(listMahasiswa, &jumlah, 123, "Alice", "Jakarta, 1 Januari 2000", 3.5);
    tambahDataMahasiswa(listMahasiswa, &jumlah, 456, "Bob", "Bandung, 2 Februari 1999", 3.7);
    tambahDataMahasiswa(listMahasiswa, &jumlah, 789, "Charlie", "Surabaya, 3 Maret 1998", 3.9);

    // Pencarian dengan Sequential Search
    DataMahasiswa *hasil = cariSequential(listMahasiswa, jumlah, 456);
    printf("Sequential Search:\n");
    cetakDataMahasiswa(hasil);

    // Urutkan data sebelum menggunakan binary search
    qsort(listMahasiswa, jumlah, sizeof(DataMahasiswa), bandingkan);

    // Pencarian dengan Binary Search
    hasil = cariBinary(listMahasiswa, jumlah, 456);
    printf("Binary Search:\n");
    cetakDataMahasiswa(hasil);

    return 0;
}
