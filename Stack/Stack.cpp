#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXSTACK 5
using namespace std;

typedef int ItemType;
/* Definisi struktur stack */
typedef struct
{
    int Item[MAXSTACK]; /* Array yang berisi data tumpukan
*/
    int Count; /* menunjukkan indeks data paling atas dari
stack */
}Stack;

void InitializeStack(Stack *S)
{
    S->Count = 0;
}

int Empty(Stack *S)
{
    return (S->Count == 0);
}

int Full(Stack *S)
{
    return (S->Count == MAXSTACK);
}

void Push(ItemType x, Stack *S)
{
    if (S->Count==MAXSTACK)
    printf("Stack penuh! Data tidak dapat masuk!");
    else
    {
        S->Item[S->Count]=x;
        ++(S->Count);
    }
}

int Pop(Stack *S)
{
    if (S->Count==0)//stack kosong
        printf ("Stack masih kosong!");
    else
    {
        --(S->Count);
        return (S->Item[S->Count]);
    }
}

int main()
{
    int i, n, input, pilih;
    char pil;
    Stack tumpukan;
    InitializeStack(&tumpukan);

    cout << "Masukkan jumlah angka untuk mengisi stack\nMaksimal 5\nMinimal 1\nIsi : ";
    cin >> n;
    cout << endl;

    for (i=0;i<n;i++)
    {
        printf ("Masukkan isi stack ke- %d : ",i+1);
        cin >> input;
        Push(input,&tumpukan);
    }   

    cout << "1.Push\n2.Pop\nPilih : ";
    cin >> pilih;
    cout << endl;

    if (pilih==1){
        for (i=n;i<MAXSTACK;i++)
        {
            printf ("Masukkan isi stack ke- %d : ",i+1);
            cin >> input;
            Push(input,&tumpukan);
        }

        for (i=MAXSTACK;i>0;i--)
        {
            printf("Isi stack ke- %d : ",i) ;
            printf("%d \n",Pop(&tumpukan));
        }
    }
    else if(pilih==2){
        /*cout << "Data sebelum di Pop :" << endl;
        for (i=n;i>0;i--)
        {
            printf("Isi stack ke- %d : ",i) ;
            printf("%d \n",Pop(&tumpukan));
        }*/
        cout << "\nData yang di Pop : " << Pop(&tumpukan) << endl;
        cout << "Sisa data :" << endl;
        for (i=n-1;i>0;i--)
        {
            printf("Isi stack ke- %d : ",i) ;
            printf("%d \n",Pop(&tumpukan));
        }
    }
    else{
        cout << "Salah" << endl;
    }
}