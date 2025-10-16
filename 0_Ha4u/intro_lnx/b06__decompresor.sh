#!/bin/bash

file_name="data.gz"

echo -e "\xA\x9 Extrayendo todo de ${file_name}"

7z x ${file_name} &>/dev/null     #  2>/dev..  >/dev...   envia todo al /dev/null

file_name="$(7z l ./data.gz | tail -n 3 | head -n 1 | awk 'NF{print $NF}')"

while [ ${file_name} ]; do
  7z x ${file_name} &>/dev/null
  echo -e "\xa\xa\x9\x9 Archivo ${file_name} obtenido."
  file_name="$(7z l ${file_name} | tail -n 3 | head -n 1 | awk 'NF{print $NF}')"
done
