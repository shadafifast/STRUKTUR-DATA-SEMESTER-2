#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to perform the partitioning of the array
int partition(int array[], int low, int high) {
    int pivot = array[high];  // Choosing the last element as pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j < high; j++) {  // Note change from j <= high to j < high
        if (array[j] <= pivot) {  // If current element is smaller than or equal to pivot
            i++;  // Increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);  // Place the pivot element at the correct position
    return (i + 1);  // Return the partitioning index
}

// Function to perform QuickSort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);  // Partitioning index
        quickSort(array, low, pi - 1);  // Sort elements before partition
        quickSort(array, pi + 1, high);  // Sort elements after partition
    }
}

// Function to print elements of the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function to run the QuickSort algorithm
int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};
    int n = sizeof(data) / sizeof(data[0]);
    quickSort(data, 0, n - 1);
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    return 0;
}
