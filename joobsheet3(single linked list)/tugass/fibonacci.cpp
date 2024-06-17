#include <stdlib.h>
#include <stdio.h>

int *bikin_fibonacci(int n) {
    int *proses_fibonacci = (int*)malloc(n * sizeof(int));
    int i;
    if (proses_fibonacci == NULL) {
        printf("gagal");
        exit(1);
    }
    proses_fibonacci[0] = 0;
    proses_fibonacci[1] = 1;

    for (i = 2; i < n; i++) {
        proses_fibonacci[i] = proses_fibonacci[i - 1] + proses_fibonacci[i - 2];
    }
    return proses_fibonacci;
}

int main() {
    int n;
    int i;
    printf("masukkan bilangan fibonacci ke berapa?\n");
    scanf("%d", &n);

    if (n < 0) {
        printf("masukkan bilangan yang positif");
        return 1;
    }
    int *proses_fibonacci = bikin_fibonacci(n);
    printf("deret pertama fibonacci:%d\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", proses_fibonacci[i]);
    }
    printf("\n");
    free(proses_fibonacci);
    return 0;
}
