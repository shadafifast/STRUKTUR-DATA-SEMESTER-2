#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct graf
{
    int jumlah_simpul;
    struct node **DaftarSimpul;
    int *sudah_dikunjungi;
};

struct node *buat_node(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

struct graf *buat_graf(int jumlah_simpul)
{
    struct graf *grafik = (struct graf *)malloc(sizeof(struct graf));
    grafik->jumlah_simpul = jumlah_simpul;
    grafik->DaftarSimpul = (struct node **)malloc(jumlah_simpul * sizeof(struct node *));
    grafik->sudah_dikunjungi = (int *)malloc(jumlah_simpul * sizeof(int));
    for (int i = 0; i < jumlah_simpul; i++)
    {
        grafik->DaftarSimpul[i] = NULL;
        grafik->sudah_dikunjungi[i] = 0;
    }
    return grafik;
}

void tambah_sisi(struct graf *grafik, int sumber, int tujuan)
{
    struct node *newnode = buat_node(tujuan);
    newnode->next = grafik->DaftarSimpul[sumber];
    grafik->DaftarSimpul[sumber] = newnode;
    newnode = buat_node(sumber); 
    newnode->next = grafik->DaftarSimpul[tujuan];
    grafik->DaftarSimpul[tujuan] = newnode;
}

// Fungsi untuk menambahkan elemen baru ke dalam antrian (queue)
void enque(int *antrian, int *belakang, int elemen)
{
    antrian[(*belakang)++] = elemen;
}

// Fungsi untuk menghapus elemen pertama dari antrian (queue)
int deque(int *antrian, int *depan)
{
    return antrian[(*depan)++];
}

void BFS(struct graf *grafik, int simpul_awal)
{
    int *antrian = (int *)malloc(grafik->jumlah_simpul * sizeof(int)); 
    int depan = 0;
    int belakang = 0;
    
    grafik->sudah_dikunjungi[simpul_awal] = 1;
    enque(antrian, &belakang, simpul_awal);
    
    while (depan < belakang)
    {
        int simpul_sekarang = deque(antrian, &depan);
        printf("%d ", simpul_sekarang);
        
        struct node *temp = grafik->DaftarSimpul[simpul_sekarang];
        while (temp)
        {
            int simpul_tetangga = temp->data;
            if (grafik->sudah_dikunjungi[simpul_tetangga] == 0)
            {
                grafik->sudah_dikunjungi[simpul_tetangga] = 1;
                enque(antrian, &belakang, simpul_tetangga);
            }
            temp = temp->next;
        }
    }
    
    free(antrian);
}

int main()
{
    struct graf *graf = buat_graf(4);
    tambah_sisi(graf, 0, 1);
    tambah_sisi(graf, 0, 2);
    tambah_sisi(graf, 1, 2);
    tambah_sisi(graf, 2, 0);
    tambah_sisi(graf, 2, 3);
    tambah_sisi(graf, 3, 3);
    tambah_sisi(graf, 4, 3);
    tambah_sisi(graf,4,2);


    printf("Hasil Breadth First Traversal dimulai dari simpul 2:\n");
    BFS(graf, 2);

    return 0;
}
