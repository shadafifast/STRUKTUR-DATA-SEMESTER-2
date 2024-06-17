//created by shadafi fastiyan
//nim 23343084
#include <stdio.h>

int main()
{
    int a[100], n, i, j, position, swap;
    printf("Masukan jumlah elemen: ");
    scanf("%d", &n);
    printf("Masukan %d buah bilangan\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n - 1; i++) // loop hanya sampai n-2 karena yang terakhir tidak perlu dibandingkan lagi
    {
        position = i;
        for (j = i + 1; j < n; j++) // mulai dari i+1
        {
            if (a[j] < a[position])
            {
                position = j;
            }
        }

        if (position != i) // Pengecekan posisi di luar loop j
        {
            swap = a[i];
            a[i] = a[position];
            a[position] = swap;
        }
    }

    printf("Array yang telah diurutkan:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);

    return 0; // Harus di luar loop pengurutan
}
