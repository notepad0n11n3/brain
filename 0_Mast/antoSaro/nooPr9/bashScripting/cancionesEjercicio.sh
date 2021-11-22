#!/bin/bash

error() {
  echo -e "$1"
}

if [ $# -ne 2 ]; then
  error  "Cantidad de parametros incorrectos"
  error  "\n\t\t $0  modificacionNombre  capeta"
  #  $0   nombre del script actual  :)
  exit 1
fi

if [ ! -d $2 ]; then
  error "La carpeta no existe"
  exit 1
fi

for goro in $( ls $2 ); do
  name="$2/${goro}"

  new_name="$2/${1}${goro}"

  mv ${name} ${new_name}

  echo " ${name} -->> ${new_name} " # | tr -s /   #! si se repita el canciones//archivo.mp4
done
