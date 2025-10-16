#include <iostream>

using namespace std;


int suma(int a, int b=2){
  return a + b;
}

int multiplicar(int a, int b){
  return a * b;
}

int main(){

  cout << "Funci[on" << endl;

  cout << suma(2) << endl;

  cout << multiplicar(2, 3);

}
