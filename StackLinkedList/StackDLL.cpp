#include <iostream>
#include <string.h>

using namespace std;

struct dataSnack{
  string namaSnack;
  int hargaSnack;

  // pointer
  dataSnack *prev;
  dataSnack *next;
};

dataSnack *head, *tail, *cur, *newNode, *del;
int maksimalSnack = 5;

void createSnack(string namaSnack, int hargaSnack){
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
  if( countSnack() == maksimalSnack ){
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

void pushSnack( string namaSnack, int hargaSnack ){

  if( isFullSnack() ){
    cout << "Stack Full!!" << endl;
  }else{
    if( isEmptySnack() ){
      createSnack(namaSnack, hargaSnack);
    }else{
      newNode = new dataSnack();
      newNode->namaSnack = namaSnack;
      newNode->hargaSnack = hargaSnack;
      newNode->prev = tail;
      tail->next = newNode;
      newNode->next = NULL;
      tail = newNode;
    }
  }

}

void popSnack()
{
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}




void displaySnack()
{
  if( isEmptySnack() ){
    cout << "Data Snack kosong" << endl;
  }else{
    cout << "\n\nIsi keranjang Anda : " << endl;
    cur = tail;
    while( cur != NULL ){
      cout << "Data Snack : " << cur->namaSnack << " - Rp." << cur->hargaSnack << endl;
      cur = cur->prev;
    }
  }
}

void peekSnack(int posisi){

  if( isEmptySnack() ){
    cout << "Data Snack kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cout << "Data Snack Posisi ke-" << posisi << " : " << cur->namaSnack << " - Rp." << cur->hargaSnack << endl;
  }

}

void changeSnack(string namaSnack, int hargaSnack, int posisi){

  if( isEmptySnack() ){
    cout << "Data Snack kosong" << endl;
  }else{
    int nomor = 1;
    cur = tail;
    while( nomor < posisi ){
      cur = cur->prev;
      nomor++;
    }
    cur->namaSnack = namaSnack;
    cur->hargaSnack = hargaSnack;
  }

}

void destroySnack()
{
  cur = head;
  while( cur != NULL ){
    del = cur;
    head = head->next;
    delete del;
    cur = cur->next;
  }
}

int main(){
    int pilih;
    cout << "========================" << endl;
    cout << "=== LIST HARGA SNACK ===" << endl;
    cout << "========================\n" << endl;
    do{
        cout << "==========PUSH==========" << endl;
        cout << "1. Siip" << endl;
        cout << "2. Chitato" << endl;
        cout << "3. Lays" << endl;
        cout << "4. Koko Crunch" << endl;
        cout << "=======================" << endl;
        cout << "5. Keluarkan Snack (Pop)" << endl;
        cout << "6. Isi Keranjang (Print item)" << endl;
        cout << "7. Keluar belanja\n" << endl;
        cout << "Pilih untuk dimasukkan keranjang : ";
        cin >> pilih;

        switch (pilih){
            case 1: /* system("cls"); */
                pushSnack("Siip", 3000);
                displaySnack();
                cout << endl;
                break;
            case 2: /*system("cls");*/
                pushSnack("Chitato", 5000);
                displaySnack();
                cout << endl;
                break;
            case 3: /* system("cls"); */
                pushSnack("Lays", 8000);
                displaySnack();
                cout << endl;
                break;
            case 4: /* system("cls"); */
                pushSnack("Koko Crunch", 10000);
                displaySnack();
                cout << endl;
                break;
            case 5: /* system("cls"); */
                popSnack();
                displaySnack();
                cout << endl;
                break;
            case 6: /* system("cls"); */
                cout << "\nIsi keranjang anda yaitu : " << endl;
                displaySnack();
                cout << endl;
                break;
            default: /* system("cls"); */
                cout << "\nMaaf, Pilihan Anda Salah";
                cout << endl;
        }
    }
    while (pilih!=7);
    return 0;
}