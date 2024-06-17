#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int times[] = {120, 110, 105, 125, 101, 100, 130, 109};
    int n = sizeof(times) / sizeof(times[0]);

    printf("Original array: \n");
    printArray(times, n);

    shellSort(times, n);

    printf("Sorted array: \n");
    printArray(times, n);
    return 0;
}