#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int list[MAX] = {1,8,4,6,0,3,5,2,7,9};

void display() {
    printf("[");
    for(int i = 0; i < MAX; i++) {
        printf("%d ", list[i]);
    }
    printf("]\n");
}

void bubbleSort() {
    int temp;
    bool swapped = false;

    for(int i = 0; i < MAX-1; i++) {
        swapped = false;
        for(int j = 0; j < MAX-1-i; j++) {
            printf("Items compared: [ %d, %d ] ", list[j], list[j+1]);

            if(list[j] > list[j + 1]) {
                printf("\tSwapping\n");
                temp = list[j];
                list[j] = list[j + 1];
                list[j+1] = temp;
                swapped = true;
            } else {
                printf("\tNot swapped\n");
            }
        }

        printf("Iteration %d#: ",(i+1));
        display();

        if(!swapped) {
            break;
        }
    }
}

int main() {
    printf("Input Array: ");
    display();
    printf("\n");
    
    bubbleSort();
    
    printf("\nOutput Array: ");
    display();

    return 0;
}
