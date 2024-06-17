#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void input();
void mergesort(int data[], int low, int high);
void merge(int data[], int low, int mid, int high);
void tampil();

int data[MAX];
int n;

int main() {
    input();
    int awal = 0, akhir = n - 1;
    mergesort(data, awal, akhir);
    tampil();
    return 0;
}

// Fungsi input
void input() {
    int i;
    printf("Masukkan jumlah total elemen: ");
    scanf("%d", &n);
    printf("\nData sebelum sorting:\n");
    for (i = 0; i < n; i++) {
        data[i] = rand() % 10000;  // Reduce range for better readability
        printf("%d\t", data[i]);
    }
    printf("\n");
}

void mergesort(int data[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(data, low, mid);
        mergesort(data, mid + 1, high);
        merge(data, low, mid, high);
    }
}

void merge(int data[], int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = data[i++];
    }

    while (j <= high) {
        temp[k++] = data[j++];
    }

    // Copy sorted data back to the original array
    for (i = low, k = 0; i <= high; i++, k++) {
        data[i] = temp[k];
    }
}

void tampil() {
    int j;
    printf("\nData setelah sorting:\n");
    for (j = 0; j < n; j++) {
        printf("%d\t", data[j]);
    }
    printf("\n");
}
