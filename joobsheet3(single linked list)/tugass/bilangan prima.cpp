#include <stdio.h>
#include <stdlib.h> // Untuk malloc dan realloc

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
int adalahPrima(int num) {
    if (num <= 1) return 0; // Bilangan kurang dari atau sama dengan 1 bukan prima
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Jika bisa dibagi oleh suatu bilangan lain, bukan prima
    }
    return 1; // Jika tidak bisa dibagi oleh bilangan lain, adalah prima
}

// Fungsi untuk mencetak bilangan prima pertama sampai ke-n
void cetakBilanganPrima(int n) {
    int jumlahPrima = 0; // Menghitung jumlah bilangan prima yang sudah ditemukan
  int *prima = (int *)malloc(sizeof(int));
 // Mengalokasikan memori untuk menyimpan bilangan prima
    if (prima == NULL) {
        printf("Gagal mengalokasikan memori.");
        return;
    }
    
    for (int num = 2; jumlahPrima < n; num++) {
        if (adalahPrima(num)) {
            jumlahPrima++;
          prima = (int *)realloc(prima, jumlahPrima * sizeof(int));
 // Mengalokasikan memori baru untuk menyimpan bilangan prima
            if (prima == NULL) {
                printf("Gagal mengalokasikan memori.");
                return;
            }
            prima[jumlahPrima - 1] = num; // Menyimpan bilangan prima ke dalam array
        }
    }
    
    // Mencetak bilangan prima yang telah ditemukan
    printf("Bilangan prima pertama sampai ke-%d adalah:\n", n);
    for (int i = 0; i < jumlahPrima; i++) {
        printf("%d ", prima[i]);
    }
    printf("\n");
    
    free(prima); // Mengepaskan memori setelah digunakan
}

int main() {
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    
    cetakBilanganPrima(n);
    
    return 0;
}
