#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi tipe data Stack
struct Stack {
    int top;
    int capacity;
    char *data;
};

// Fungsi untuk membuat stack baru
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*) malloc(stack->capacity * sizeof(char));
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

// Fungsi untuk menambahkan karakter ke dalam stack (push)
void push(struct Stack* stack, char character) {
    if (isFull(stack)) {
        printf("Stack penuh. Tidak bisa menambahkan karakter.\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = character;
}

// Fungsi untuk menghapus karakter dari stack (pop)
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong. Tidak bisa mengambil karakter.\n");
        return '\0';
    }
    char character = stack->data[stack->top];
    stack->top--;
    return character;
}

// Fungsi untuk membalikkan kata menggunakan stack
char* reverseString(char *string) {
    int length = strlen(string);
    struct Stack* stack = createStack(length);
    
    // Push setiap karakter dari string ke dalam stack
    for (int i = 0; i < length; i++) {
        push(stack, string[i]);
    }

    // Pop setiap karakter dari stack untuk membalikkan string
    for (int i = 0; i < length; i++) {
        string[i] = pop(stack);
    }

    free(stack->data);
    free(stack);

    return string;
}

// Fungsi utama
int main() {
    char kata[100];
    int pilihan;

    do {
        printf("\nMenu:\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan kata: ");
                scanf("%s", kata);
                break;
            case 2:
                printf("Kata setelah dibalik: %s\n", reverseString(kata));
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 3);

    return 0;
}
