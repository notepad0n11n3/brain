#include <iostream>

using namespace std;

int main(){

  int lista[] = { 100, 200, 300 };

//int limite = sizeof(lista) / 4 ;   // un entero tiene 4 bites,   sizeof(lista)  retorna 12  bites
  int limite = sizeof(lista) / sizeof(lista[0]);

//for(int i=0; i < user_data; i++){
  for(int i=0; i < limite; i += 1){
    if(lista[i] == 200){
    //break;
      continue;
    }
    cout << lista[i] << endl;
  }

}
