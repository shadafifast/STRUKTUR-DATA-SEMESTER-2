#include<stdio.h>

void ShellSort(int a[], int n) {
    int i, j, increment, tmp;
    for (increment = n / 2; increment > 0; increment /= 2) {
        for (i = increment; i < n; i++) {
            tmp = a[i];  // Menyimpan nilai sementara
            for (j = i; j >= increment && tmp < a[j - increment]; j -= increment) {
                a[j] = a[j - increment];
            }
            a[j] = tmp;
        }
    }
}

int main() {
    int i, n, a[10];
    printf("Masukan jumlah elemen (maksimal 10): ");
    scanf("%d", &n);
    if (n > 10 || n < 1) {
        printf("Jumlah elemen harus antara 1 dan 10.\n");
        return 1;
    }

    printf("Masukan %d bilangan: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ShellSort(a, n);

    printf("Elemen yang telah diurutkan adalah:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    printf("\n");

    return 0;
}
