#include <stdio.h>

// Fungsi untuk mengurutkan subbagian array a[i..j]
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return; // subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // Sort the left sub-array recursively
    merge_sort(i, mid, a, aux);
    // Sort the right sub-array recursively
    merge_sort(mid + 1, j, a, aux);

    int pointer_left = i;  // points to the beginning of the left sub-array
    int pointer_right = mid + 1; // points to the beginning of the right sub-array
    int k;

    // Merge the two halves into auxiliary array aux
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) { // if left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) { // if right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) { // if element from left sub-array is smaller
            aux[k] = a[pointer_left];
            pointer_left++;
        } else { // if element from right sub-array is smaller
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    // Copy the sorted elements back to the original array a
    for (k = i; k <= j; k++) {
        a[k] = aux[k];
    }
}

int main() {
    int a[100], aux[100], n, i;
    printf("Masukan jumlah elemen di dalam array:\n");
    scanf("%d", &n);
    printf("Masukan %d bilangan integer\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(0, n - 1, a, aux);
    printf("Menampilkan array yang telah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
