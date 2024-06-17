//created by shadafi fastiyan
//nim 23343084
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk merepresentasikan sebuah buku akademik
struct BukuAkademik {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct BukuAkademik *prev;
    struct BukuAkademik *next;
};

// Tipe data untuk merepresentasikan Double Linked List
struct DoubleLinkedList {
    struct BukuAkademik *head;
};

// Fungsi untuk membuat simpul baru
struct BukuAkademik* buat_simpul(char judul[], char pengarang[], int tahun) {
    struct BukuAkademik *newNode = (struct BukuAkademik*)malloc(sizeof(struct BukuAkademik));
    strcpy(newNode->judul, judul);
    strcpy(newNode->pengarang, pengarang);
    newNode->tahun = tahun;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan buku baru ke akhir linked list
void tambah_buku(struct DoubleLinkedList *list, char judul[], char pengarang[], int tahun) {
    struct BukuAkademik *newNode = buat_simpul(judul, pengarang, tahun);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct BukuAkademik *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menghapus buku akademik berdasarkan judulnya
void hapus_buku(struct DoubleLinkedList *list, char judul[]) {
    struct BukuAkademik *current = list->head;
    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Fungsi untuk menampilkan daftar buku akademik dalam perpustakaan
void tampilkan_daftar(struct DoubleLinkedList *list) {
    struct BukuAkademik *current = list->head;
    while (current != NULL) {
        printf("Judul: %s\n", current->judul);
        printf("Pengarang: %s\n", current->pengarang);
        printf("Tahun: %d\n", current->tahun);
        printf("---------------------\n");
        current = current->next;
    }
}

// Fungsi utama
int main() {
    struct DoubleLinkedList perpustakaan;
    perpustakaan.head = NULL;

    // Menambahkan beberapa buku akademik ke dalam perpustakaan
    tambah_buku(&perpustakaan, "Introduction to Algorithms", "Thomas H. Cormen", 1990);
    tambah_buku(&perpustakaan, "Data Structures and Algorithm Analysis in C", "Mark Allen Weiss", 1992);
    tambah_buku(&perpustakaan, "Operating System Concepts", "Abraham Silberschatz", 1983);

    printf("Daftar Buku Akademik dalam Perpustakaan:\n");
    tampilkan_daftar(&perpustakaan);

    // Menghapus buku akademik "Introduction to Algorithms"
    hapus_buku(&perpustakaan, "Introduction to Algorithms");
    printf("\nSetelah menghapus 'Introduction to Algorithms':\n");
    tampilkan_daftar(&perpustakaan);

    return 0;
}
