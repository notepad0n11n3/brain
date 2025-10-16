#!/bin/bash

echo -n "Escribe un n[umero: "
read limite

for (( i = 0; i < ${limite}; i++ ));do
  echo ${i}
done
