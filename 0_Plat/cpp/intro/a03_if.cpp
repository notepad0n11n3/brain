#include <iostream>

using namespace std;

int main(){

  int edad = 0;
  cout << "\tEdad: ";
  cin >> edad;

  if(edad < 18 || edad > 40){
    cout << "\n\tNo puedes votar" << endl;
  }else {
    cout << "\n\tPuedes votar ***" << endl;
  }

}
