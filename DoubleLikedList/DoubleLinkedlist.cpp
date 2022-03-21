#include <iostream>
#include <string.h>
using namespace std;

struct DoubleLinkedNode
{
    int bil;
    struct DoubleLinkedNode *back;
    struct DoubleLinkedNode *next;
};

struct DoubleLinkedNode *head, *tail;

void bentuk_awal()
{
    struct DoubleLinkedNode *awal;
    int j=0;char jawab[2];
    while(1)
    {
        awal = (struct DoubleLinkedNode*) malloc(sizeof (struct DoubleLinkedNode));
        printf("Masukkan bilangan :");
        scanf("%d",&awal->bil);
        if(j==0)
        {
            awal->next=NULL;
            awal->back=NULL;
            head = awal;
            tail = awal;
        }
        else
        {
            tail->next=awal;
            awal->next=NULL;
            awal->back=tail;
            tail = awal;
        }

        printf("Ada data lagi(y/t):"); scanf("%s", &jawab);
    if((strcmp(jawab,"Y")==0)||(strcmp(jawab,"y")==0))
        {
            j++;continue;
        }
    else if ((strcmp(jawab,"T")==0) || (strcmp(jawab,"t") == 0))
        break;
    }
}

void tampil_list_fifo()
{
    struct DoubleLinkedNode *lifo;
    printf("Data Bilangan yang Telah Diinputkan secara FIFO :\n");
    lifo = tail;
    while(lifo!=NULL)
    {
        printf("%d\t",lifo->bil);
        lifo=lifo->back;
    }
    printf("\n");
}

void tampil_list_lifo()
{
    struct DoubleLinkedNode *fifo;
    printf("Data Bilangan yang Telah Diinputkan secara LIFO :\n");
    fifo = head;
    while(fifo!=NULL)
    {
        printf("%d\t",fifo->bil);
        fifo=fifo->next;
    }
    printf("\n");
}

void sisip_simpul_tengah()
{
    int num;
    struct DoubleLinkedNode *sisip, *stl, *sbl;
    sisip=(struct DoubleLinkedNode*)malloc(sizeof(struct DoubleLinkedNode));
    printf("Tuliskan bilangan yang akan disisipkan : ");
    scanf("%d",&sisip->bil);
    sisip->next=NULL;
    sisip->back=NULL;
    printf("Bilangan disisipkan sebelum data : ");
    scanf("%d",&num);
    stl = head;
    do {
        sbl = stl;
        stl = stl->next;
    }
    while (stl->bil!=num);
    sisip->next= stl;
    sisip->back= sbl;
    sbl->next= sisip;
    stl->back= sisip;
}

void hapus_simpul()
{
    int num;
    struct DoubleLinkedNode *sbl, *hapus, *stl;
    printf("Masukkan data yang akan dihapus : ");
    scanf("%d",&num);
    hapus = head;
    //Menghapus Simpul Awal
    if (hapus->bil == num)
    {
    head = head->next;
    head->back = NULL;
    free(hapus);
    }
    else
    {
        do{
            sbl = hapus;
            hapus = hapus->next;}
        while (hapus->bil!=num);
        //Menghapus Simpul Terakhir
        if (hapus->next == NULL)
        {
            sbl->next=NULL;
            tail = sbl;
            free(hapus);
        }
        //Menghapus Simpul di Tengah
        else
        {
            stl = hapus->next;
            sbl->next = stl;
            stl->back = sbl;
            free(hapus);
        }
    }
}

int main(){
    bentuk_awal();
    tampil_list_lifo();
    tampil_list_fifo();
    sisip_simpul_tengah();
    hapus_simpul();
}