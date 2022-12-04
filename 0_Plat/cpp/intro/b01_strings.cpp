#include <iostream>

#include <string>

using namespace std;

int main(){

  char texto[] = {'H','o','l','a'};

  cout << texto << endl;

  // hasta aca funciona normal sin #include <string>

  string texto2 = "Hello olo";  // sin []   NO [] ...!!! 

  cout << texto2 << endl;
  cout << texto2.size();

  string texto3 = "10";

  cout << endl << stoi(texto3) << "\tstring to int <3 <3 <3";
              //  stof()      string to float

}
