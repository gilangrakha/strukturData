#include <iostream>
#include <string.h>
using namespace std;

struct dataSnack{
    string namaSnack;
    int hargaSnack;
    dataSnack *next;
    dataSnack *prev;
};

dataSnack *head, *tail, *del, *newNode, *cur;
int maxSnack = 5;

void createBarang(string namaSnack, int hargaSnack){
  head = new dataSnack();
  head->namaSnack = namaSnack;
  head->hargaSnack = hargaSnack;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countSnack()
{
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

bool isFullSnack()
{
  if( countSnack() == maxSnack ){
    return true;
  }else{
    return false;
  }
}

bool isEmptySnack()
{
  if( countSnack() == 0 ){
    return true;
  }else{
    return false;
  }
}

void pushSnack (string namaSnack, int hargaSnack){
    if (isFullSnack){
        cout << "Stack Penuh !!!\n" << endl;
    }
    else{
        if(isEmptySnack){
            head = new dataSnack();
            head->namaSnack = namaSnack;
            head->hargaSnack = hargaSnack;
            head->prev = NULL;
            head->next = NULL;
            head = tail;
        }
        else{
            newNode = new dataSnack();
            newNode->namaSnack = namaSnack;
            newNode->hargaSnack  = hargaSnack;
            newNode->prev = tail;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void printSnack(){
    if (isEmptySnack){
        cout << "Stack masih kosong !!!\n" << endl;
    }
    else{
        cout << "Data snack : " << endl;
        cur=tail;
        while(cur != NULL){
            cout << "Data snack : " << cur->namaSnack << " - Rp." << cur->namaSnack << endl;
            cur = cur->prev;
        }
    }
}

/*void inputSnack(string namaSnack, int hargaSnack){
    cout << "Masukkan nama snack : " << namaSnack << endl;
    cout << "Masukkan harga snack : " << hargaSnack << endl;
}*/

int main(){

    pushSnack("Siip", 3000);
    printSnack();

    return 0;
}