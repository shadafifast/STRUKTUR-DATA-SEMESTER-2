#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nama_barang[50];
    int kuantitas_produk;
} Barang;

void input_barang(Barang *b, int j) {
    for (int i = 0; i < j; i++) {
        printf("Masukkan nama barang ke-%d:\n", i + 1);
        scanf("%s", b[i].nama_barang);
        printf("Masukkan kuantitas produk barang %s:\n", b[i].nama_barang);
        scanf("%d", &b[i].kuantitas_produk);
    }
}

void bubble_sort(Barang *b, int j) {
    bool swapped;
    int swapcounter = 0;
    Barang temp;
    do {
        swapped = false;
        for (int i = 0; i < j - 1; i++) {
            if (b[i].kuantitas_produk > b[i + 1].kuantitas_produk) {
                temp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp;
                swapped = true;
                swapcounter++;
            }
        }
    } while (swapped);
}

void insertion_sort(Barang *b, int j) {
    int i, k;
    Barang key;
    for (i = 1; i < j; i++) {
        key = b[i];
        k = i - 1;
        while (k >= 0 && strcmp(b[k].nama_barang, key.nama_barang) > 0) {
            b[k + 1] = b[k];
            k = k - 1;
        }
        b[k + 1] = key;
    }
}

void print_barang(Barang *b, int j, bool nama, bool kuantitas) {
    printf("\nDaftar Barang:\n");
    for (int i = 0; i < j; i++) {
        if (nama && kuantitas) {
            printf("Nama Barang: %s, Kuantitas Produk: %d\n", b[i].nama_barang, b[i].kuantitas_produk);
        } else if (nama) {
            printf("Nama Barang: %s\n", b[i].nama_barang);
        } else if (kuantitas) {
            printf("Kuantitas Produk: %d\n", b[i].kuantitas_produk);
        }
    }
}

int main() {
    int jumlah_barang;
    printf("Berapa banyak barang yang akan diinputkan?\n");
    scanf("%d", &jumlah_barang);
    Barang b[jumlah_barang];

    bool ulang = true;
 
    do {
        
input_barang(b, jumlah_barang);

        int choice;
        printf("Pilih jenis pengurutan:\n");
        printf("1. Bubble Sort (berdasarkan kuantitas produk)\n");
        printf("2. Insertion Sort (berdasarkan nama barang)\n");
        printf("3. Keluar\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubble_sort(b, jumlah_barang);
                print_barang(b, jumlah_barang, false, true); // Cetak hanya kuantitas
                break;
            case 2:
                insertion_sort(b, jumlah_barang);
                print_barang(b, jumlah_barang, true, false); // Cetak hanya nama barang
                break;
            case 3:
                ulang = false;
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (ulang);

    return 0;
}
