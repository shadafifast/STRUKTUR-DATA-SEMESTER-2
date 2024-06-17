#include<stdio.h>
#define ukuran 5
int items[ukuran], belakang = -1, depan = -1;

void enque(int);
void deque();
void tampilkan();

int main(){
    deque();
    enque(7);
    enque(8);
    enque(6);
    enque(5);
    enque(4);
    enque(9);
    tampilkan();
    deque();
    tampilkan();
    return 0;
}

void enque(int value){
    if(belakang == ukuran - 1){
        printf("\n queue telah penuh ");
    }else{
        if (depan == -1){
            depan = 0;
        }
        belakang++;
        items[belakang] = value;
    }
}

void deque(){
    if(depan == -1){
        printf("queue masih kosong");
    }else{
        printf("\n nilai dihapus adalah : %d", items[depan]);
        depan++;
        if(depan > belakang)
            depan = belakang = -1;
    }
}

void tampilkan(){
    if(belakang == -1){
        printf("\nqueue kosong");
    }else{
        int i;
        printf("\nelemen pada queue adalah\n");
        for(i = depan; i <= belakang; i++){
            printf("%d\t", items[i]);
        }
    }
}
