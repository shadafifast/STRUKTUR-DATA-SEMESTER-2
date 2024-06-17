#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk merepresentasikan sebuah mobil
struct Mobil {
    char no_plat[20];
    char merk[50];
    char pemilik[100];
    struct Mobil *prev;
    struct Mobil *next;
};

// Tipe data untuk merepresentasikan Double Linked List
struct DoubleLinkedList {
    struct Mobil *head;
};

// Fungsi untuk membuat simpul baru
struct Mobil* buat_simpul(char no_plat[], char merk[], char pemilik[]) {
    struct Mobil *newNode = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(newNode->no_plat, no_plat);
    strcpy(newNode->merk, merk);
    strcpy(newNode->pemilik, pemilik);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan mobil baru ke akhir linked list (parkiran)
void tambah_mobil(struct DoubleLinkedList *list, char no_plat[], char merk[], char pemilik1[], char pemilik2[], char pemilik3[]) {
    char pemilik[100];
    sprintf(pemilik, "%s %s %s", pemilik1, pemilik2, pemilik3);
    struct Mobil *newNode = buat_simpul(no_plat, merk, pemilik);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Mobil *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Fungsi untuk menghapus mobil dari linked list berdasarkan nomor plat
void hapus_mobil(struct DoubleLinkedList *list, char no_plat[]) {
    struct Mobil *current = list->head;
    while (current != NULL) {
        if (strcmp(current->no_plat, no_plat) == 0) {
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

// Fungsi untuk menampilkan daftar mobil dalam perparkiran
void tampilkan_daftar(struct DoubleLinkedList *list) {
    struct Mobil *current = list->head;
    while (current != NULL) {
        printf("No Plat: %s\n", current->no_plat);
        printf("Merk: %s\n", current->merk);
        printf("Pemilik: %s\n", current->pemilik);
        printf("---------------------\n");
        current = current->next;
    }
}

// Fungsi utama
int main() {
    struct DoubleLinkedList perparkiran;
    perparkiran.head = NULL;

    // Menambahkan beberapa mobil ke dalam perparkiran
    tambah_mobil(&perparkiran, "B 1234 ABC", "Toyota","Joel");
    tambah_mobil(&perparkiran, "B 5678 XYZ", "Honda",  "Rafki");
    tambah_mobil(&perparkiran, "B 9876 DEF", "Suzuki", "Shadafi");

    printf("Daftar Mobil dalam Perparkiran:\n");
    tampilkan_daftar(&perparkiran);

    // Menghapus mobil dengan nomor plat "B 5678 XYZ"
    hapus_mobil(&perparkiran, "B 5678 XYZ");
    printf("\nSetelah menghapus mobil dengan nomor plat 'B 5678 XYZ':\n");
    tampilkan_daftar(&perparkiran);

    return 0;
}
