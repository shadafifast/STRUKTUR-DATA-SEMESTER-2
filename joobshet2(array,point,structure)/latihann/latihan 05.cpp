//created by shadafi fastiyan
//nim 23343084
#include <stdio.h>
#include <string.h> // Include string.h for strcpy function

struct Mahasiswa {
    char nama[50];
    char jurusan[50];
    int nilai;
};

typedef struct Mahasiswa data;

int main(void) {
    data mhs01;

    strcpy(mhs01.nama, "Muhammad Rafki");
    strcpy(mhs01.jurusan, "Informatika");
    mhs01.nilai = 100;

    printf("%s adalah mahasiswa jurusan %s\n", mhs01.nama, mhs01.jurusan); // Corrected the variable name
    printf("memperoleh nilai UAS %i \n", mhs01.nilai);

    return 0;
}