#include <iostream>

using namespace std;

int main(){
  /*
  while(true){
    char repuesta;
    cout << "Menu hardcore" << endl;
    cout << "\t\tDesea continuar: " << endl;
    cin >> repuesta;
    if(repuesta == 'n'){
      cout << "bye bye";
      break;
    }
  }
  */

  do{
    char repuesta;
    cout << "Menu hardcore" << endl;
    cout << "\t\tDesea continuar: " << endl;
    cin >> repuesta;
    if(repuesta == 'n'){
      cout << "bye bye";
      break;
    }
  }while(true);
}
