//created by shadafi fastiyan
//nim 23343084
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}

void printArray(int array[], int size) // Ubah nama fungsi agar konsisten
{
    for (int i = 0; i < size; i++) // Gunakan 'size' bukan 'n'
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted array in Ascending Order:\n");
    printArray(data, size);
    return 0; // Tambahkan return statement
}
