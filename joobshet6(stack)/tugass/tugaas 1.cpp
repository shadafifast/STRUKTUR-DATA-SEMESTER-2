//created by shadafi fastiyan
//nim 23343084
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk merepresentasikan seorang mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[100];
    float nilai;
};

// Definisi tipe data Stack
struct Stack {
    int top;
    int capacity;
    struct Mahasiswa *data;
};

// Fungsi untuk membuat stack baru
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (struct Mahasiswa*) malloc(stack->capacity * sizeof(struct Mahasiswa));
    return stack;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Fungsi untuk menambahkan data ke dalam stack (push)
void push(struct Stack* stack, char nim[], char nama[], float nilai) {
    if (isFull(stack)) {
        printf("Stack penuh. Tidak bisa menambahkan data.\n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top].nim, nim);
    strcpy(stack->data[stack->top].nama, nama);
    stack->data[stack->top].nilai = nilai;
}

// Fungsi untuk menghapus data dari stack (pop)
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong. Tidak bisa menghapus data.\n");
        return;
    }
    stack->top--;
}

// Fungsi untuk menampilkan data dalam stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Data Mahasiswa dalam Stack:\n");
    printf("%-15s %-30s %-10s\n", "NIM", "Nama", "Nilai");
    for (int i = stack->top; i >= 0; i--) {
        printf("%-15s %-30s %-10.2f\n", stack->data[i].nim, stack->data[i].nama, stack->data[i].nilai);
    }
}

// Fungsi untuk membandingkan dua nilai float (digunakan untuk sorting)
int compare(const void *a, const void *b) {
    float nilai_a = ((struct Mahasiswa*)a)->nilai;
    float nilai_b = ((struct Mahasiswa*)b)->nilai;
    if (nilai_a < nilai_b) return -1;
    if (nilai_a > nilai_b) return 1;
    return 0;
}

// Fungsi untuk melakukan sorting data dalam stack berdasarkan nilai mahasiswa
void sort(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong. Tidak ada data untuk diurutkan.\n");
        return;
    }
    qsort(stack->data, stack->top + 1, sizeof(struct Mahasiswa), compare);
}

// Fungsi utama
int main() {
    struct Stack* stack = createStack(10); // Membuat stack dengan kapasitas 10

    // Menambahkan beberapa data mahasiswa ke dalam stack
    push(stack, "101", "Alice", 85.5);
    push(stack, "102", "Bob", 90.0);
    push(stack, "103", "Charlie", 78.3);

    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Hapus Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Urutkan Data Mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                char nim[15], nama[100];
                float nilai;
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                printf("Masukkan Nama: ");
                scanf("%s", nama);
                printf("Masukkan Nilai: ");
                scanf("%f", &nilai);
                push(stack, nim, nama, nilai);
                break;
            }
            case 2:
                pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                sort(stack);
                printf("Data Mahasiswa telah diurutkan berdasarkan nilai.\n");
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    free(stack->data);
    free(stack);

    return 0;
}
