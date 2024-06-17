#include<stdio.h>
#include<stdlib.h>
#define MAX 7

int intArray[MAX] = {4,6,3,2,1,9,7};

void printline(int count) {
    int i;
    for(i = 0; i < count-1; i++) {
        printf("=");
    }
    printf("=\n");
}

void display() {
    printf("[");
    for(int i = 0; i < MAX; i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

void insertionSort() {
    int valueToInsert, holePosition;

    for(int i = 1; i < MAX; i++) {
        valueToInsert = intArray[i];
        holePosition = i;

        while (holePosition > 0 && intArray[holePosition-1] > valueToInsert) {
            intArray[holePosition] = intArray[holePosition-1];
            holePosition--;
            printf("item moved: %d\n", intArray[holePosition]);
        }

        printf("item inserted: %d, at position: %d\n", valueToInsert, holePosition);
        intArray[holePosition] = valueToInsert;

        printf("Iteration %d#: ", i);
        display();
    }
}

int main() {
    printf("Input Array: ");
    display();
    printline(50);
    insertionSort();
    printf("Output Array: ");
    display();
    printline(50);

    return 0;
}
