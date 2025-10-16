#ifndef OPERACIONES_C_INCLUDED
#define OPERACIONES C INCLUDED

int sumar(int op1, int op2){
  return op1 + op2;
}

int restar(int op1, int op2){
  return op1 - op2;
}

int multiplicar(int op1, int op2){
  return op1 * op2;
}

float dividir(int op1, int op2){
  if(op2 == 0){
    return 0;
  }
  else{
    return (float)op1/op2;  // el resultado se convierte a float <<---
  }
}

#endif  //OPERACIONES_C_INCLUDED
