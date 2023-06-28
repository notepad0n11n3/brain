#!/bin/bash

# Ctrl+C
function mangoEX(){
  echo -e "\n\n[!] Saliendo...\n"
  tput cnorm; exit 1
}
trap mangoEX INT


tput civis # Ocultar el cursor

for port in $(seq 1 65535); do
  (echo '' > /dev/tcp/127.0.0.1/$port) 2>/dev/null && echo "[+] $port - OPEN" &
done; wait

# Recuperamos el cursor
tput cnorm
