#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int Data[MAX];

// Prosedur menukar data
void Tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prosedur pengurutan metode Quick Sort non-rekursif
void QuickSortNonRekursif() {
    struct tump {
        int Kiri;
        int Kanan;
    } Tumpukan[MAX];

    int i, j, L, R, x, ujung = 0;

    Tumpukan[ujung].Kiri = 0;
    Tumpukan[ujung].Kanan = MAX - 1;

    while (ujung >= 0) {
        L = Tumpukan[ujung].Kiri;
        R = Tumpukan[ujung].Kanan;
        ujung--;

        while (R > L) {
            i = L;
            j = R;
            x = Data[(L + R) / 2];
            while (i <= j) {
                while (Data[i] < x) i++;
                while (x < Data[j]) j--;
                if (i <= j) {
                    Tukar(&Data[i], &Data[j]);
                    i++;
                    j--;
                }
            }
            if (i < R) {
                ujung++;
                Tumpukan[ujung].Kiri = i;
                Tumpukan[ujung].Kanan = R;
            }
            if (L < j) {
                ujung++;
                Tumpukan[ujung].Kiri = L;
                Tumpukan[ujung].Kanan = j;
            }
        }
    }
}

// Program utama untuk menguji QuickSort
int main() {
    srand(0);  // Inisialisasi seed untuk pembangkit bilangan acak

    // Membangkitkan bilangan acak
    printf("DATA SEBELUM TERURUT\n");
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 100 + 1;  // Menghasilkan bilangan acak antara 1 dan 100
        printf("Data ke %d : %d\n", i, Data[i]);
    }

    QuickSortNonRekursif();

    // Menampilkan data setelah terurut
    printf("\nDATA SETELAH TERURUT\n");
    for (int i = 0; i < MAX; i++) {
        printf("Data ke %d : %d\n", i, Data[i]);
    }

    return 0;
}
