#include<stdio.h>
#include<stdlib.h>

struct data_mahasiswa{
    int nim;
    char nama[50];
    double ipk;
    int tanggal_lahir;
};

void input_data_mahasiswa(struct data_mahasiswa *mahasiswa) {
    printf("Input nama mahasiswa: ");
    scanf("%s", mahasiswa->nama);
    printf("Input NIM mahasiswa: ");
    scanf("%d", &mahasiswa->nim);
    printf("Input IPK mahasiswa: ");
    scanf("%lf", &mahasiswa->ipk);
    printf("Input Tanggal Lahir: ");
    scanf("%d", &mahasiswa->tanggal_lahir);
}

void menampilkan_data_mahasiswa(struct data_mahasiswa *mahasiswa) {
    printf("\nData Mahasiswa\n");
    printf("Nama: %s\n", mahasiswa->nama);
    printf("NIM: %d\n", mahasiswa->nim);
    printf("IPK: %.2lf\n", mahasiswa->ipk);
    printf("Tanggal Lahir: %d\n", mahasiswa->tanggal_lahir);
}

int main() {
    struct data_mahasiswa mahasiswa;

    input_data_mahasiswa(&mahasiswa);
    menampilkan_data_mahasiswa(&mahasiswa);

    return 0;
}
