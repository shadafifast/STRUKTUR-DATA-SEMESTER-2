#include "stdio.h"

int main() {
    int L[20], temp, i, j, n = 6, m;
    printf("Pengurutan berdasarkan Shell Sort\nMasukkan %d elements: \n", n);
    
    // Reading input elements into array L
    for (i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    printf("\nSebelum sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");

    // Starting the Shell sort algorithm
    for (m = n / 2; m > 0; m /= 2) { // Decrease the gap by half each iteration
        for (j = m; j < n; j++) {
            // Perform insertion sort with gap 'm'
            temp = L[j];
            int k;
            for (k = j; k >= m && L[k - m] > temp; k -= m) {
                L[k] = L[k - m];
            }
            L[k] = temp;
        }
    }

    printf("Setelah sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");

    return 0;
}
