#include<stdio.h>
#include<malloc.h>
#include <iostream>
using namespace std;

typedef struct node
{
    int Item;
    struct node *link;
}Node;

typedef struct {
    Node *Front;
    Node *Rear;
}Queue;

// Prosedur untuk menyisipkan data pada antrian
void Tambah(Queue *Q, int y)
{
    Node *ptr;
    ptr=(Node *) malloc(sizeof(Node));
    ptr->Item=y;
    ptr->link=NULL;
    if(Q->Front ==NULL)
    {
        Q->Front = Q->Rear = ptr;
    }
    else
    {
        Q->Rear->link=ptr;
        Q->Rear=ptr;
    }
}

// Prosedur untuk menghapus data dari antrian
int Hapus(Queue *Q)
{
    int num;
    if(Q->Front==NULL)
    {
        printf("\n\n\t\tAntrian Kosong\n\n");
        return(0);
    }
    else
    {
        num=Q->Front->Item;
        Q->Front = Q->Front->link;
        if(Q->Front == NULL)
        Q->Rear = NULL;
        //printf("\nNilai yang dihapus : %d \n",num);
        return(num);
    }
}

void Tampil(Node *N)
{
    printf ("\nFront -> ");
    while (N != NULL)
    {
    if(N->link == NULL)
    {
        printf("%5d", N->Item);
        printf(" <- Rear");
    }
    else
        printf("%5d", N->Item);
        N = N->link;
    }
}

int Count(Node *N)
{
    int c=0;
    while (N != NULL)
    {
        N = N->link;
        c++;
    }
    return c;
}

int main()
{
    int item, pil;
    Queue Q;
    Q.Front = Q.Rear = NULL;

    do{
        cout << "\n=======MENU PROGRAM QUEUE LINKED LIST=======\n" << endl;
        cout << "List angka untuk Queue :" << endl;
        cout << "\n1, 2, 3, 4, 5, 6, 7\n" << endl;
        cout << "Ketik 8 untuk print Queue" << endl;
        cout << "Ketik 9 untuk mengetahui isi Queue" << endl;
        cout << "Ketik 10 untuk hapus Queue" << endl;
        cout << "Ketik 11 untuk menutup program\n" << endl;
        cout << "Masukkan angka yang ingin dimasukkan : ";
        cin >> pil;

        switch (pil){
            case 1: /* system("cls"); */
                Tambah(&Q, 1);
                cout << endl;
                break;
            case 2: /* system("cls"); */
                Tambah(&Q, 2);
                cout << endl;
                break;
            case 3: /* system("cls"); */
                Tambah(&Q, 3);
                cout << endl;
                break;
            case 4: /* system("cls"); */
                Tambah(&Q, 4);
                cout << endl;
                break;
            case 5: /* system("cls"); */
                Tambah(&Q, 5);
                cout << endl;
                break;
            case 6: /* system("cls"); */
                Tambah(&Q, 6);
                cout << endl;
                break;
            case 7: /* system("cls"); */
                Tambah(&Q, 7);
                cout << endl;
                break;
            case 8: /* system("cls"); */
                Tampil(Q.Front);
                cout << endl;
                break;
            case 9: /* system("cls"); */
                printf("\nJumlah data pada antrian : %d", Count(Q.Front));
                cout << endl;
                break;
            case 10: /* system("cls"); */
                item=Hapus(&Q);
                printf("\nNilai yang dihapus : %d",item);
                Tampil(Q.Front);
                cout << endl;
                break;
        }
    }
    while (pil!=11);
}