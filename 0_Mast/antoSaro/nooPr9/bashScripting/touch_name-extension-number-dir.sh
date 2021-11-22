#!/bin/bash

#  nombre  extension  n[umero  ruta
error() {
  echo $1
  exit 1
}

if [ $# -ne 4 ]; then
  error "Uso: script nombre extensi[on n[umero ruta"
fi

if [ ! -d $4 ]; then
  error "Error: el directorio no existe"
fi

if [ $3 -lt 1 ]; then
  error "Error: el n[umero de ficheros no pude ser menor que 1"
fi

for (( i = 1; i <= $3; i++ )); do
  name="${4}/${1}${i}.${2}"
  if [ $i -lt 10 ]; then
    name="${4}/${1}0${i}.${2}"
  fi
  touch $name
  echo "Fichero ${name} creado" | tr -s /
done
