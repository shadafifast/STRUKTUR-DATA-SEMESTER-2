#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 20

void insertionsort(int array[]){
    int i,j,key;
    for (int i = 0; i < max; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >=0 && array [j] >key)
        {
            array [j+1]=array[j];
            j--;
        }
        array[j + 1]=key;
    }
}

int main(){
    int data_awal[max], data_urut[max];
    time_t k1, k2;

    printf("sebelum pengurutan;\n");
    for (int i = 0; i < max; i++)
    {
        srand(time(NULL) * (i + 1));
        data_awal[i] = rand() % 100 + 1;
        printf( "%d ", data_awal[i]);
    }
    printf("\n");

    printf("setelah pengurutan:\n");
    for(int i = 0; i < max; i++)
        data_urut[i] = data_awal[i];
    time(&k1);
    insertionsort(data_urut);
    time(&k2);
    for(int i = 0; i < max; i++)
        printf("%d ", data_urut[i]);
    printf("\nWaktu = %ld\n", k2 - k1); 

    return 0;
}
