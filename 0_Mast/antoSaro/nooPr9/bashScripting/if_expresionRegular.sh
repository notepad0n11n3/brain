#!/bin/bash

echo -n "Instalar programa? [s/n]:"
read resultado

if [[ ${resultado} == [sS] ]]; then #expresionRegular en comparaci[on s S  :) :) :)
#if [ $resultado == "s" -a $resultado == "S" ];then
  echo "Instalando programa"
elif [[ ${resultado} == [nN] ]];then
  echo "El programa no se va a instalar"
else
  echo "Opci[on invalida"
fi


#     -a   and
#     -o   or
