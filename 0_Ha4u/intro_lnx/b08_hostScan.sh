#!/bin/bash

# Ctrl+C
function mangoEX(){
  echo -e "\n\n[!] Saliendo...\n"
  tput cnorm    # recuperamos el cursor de consola
  exit 1
}
trap mangoEX INT


tput civis # Ocultar el cursor

for i in $(seq 1 254); do
  timeout 1 bash -c "ping -c 1 192.168.1.$i &>/dev/null" && echo "[+] Host 192.168.1.$i - ACTIVE" &
done; wait

tput cnorm    # recuperamos el cursor de consola
