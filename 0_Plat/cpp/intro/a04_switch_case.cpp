#include <iostream>

using namespace std;

int main(){

  int user_option = -1;

  cout << "\n\tIngrese una opcion: ";
  cin >> user_option;

  switch(user_option){
    case 1:
      cout << "Option 1";
      break;

    case 2:
      cout << "Option 2";
      break;

    default:
      cout << "\n\tError... wrong ";
      break;
  }
}
