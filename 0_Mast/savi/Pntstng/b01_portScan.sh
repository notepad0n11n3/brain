#!/bin/bash

#  ./portScan.sh  <ip-address>
# bash -c "echo '' > /dev/tcp/192.168.0.16/88" && echo "[*] Puerto abierto"
#                    /dev/tcp/ipHereIpHere/Puerto

if [ $1 ]; then   # si existe un argumento <ip-address> ejecuta el if  [o go al else
  ip_address=$1
  for portGoro in $( seq 1 65535 );do
    timeout 1 bash -c "echo '' > /dev/tcp/${ip_address}/${portGoro}" 2>/dev/null && echo " [*] ${portGoro} - OPEN " &   # &  atravez de hilos '&' se ejecuta multiples tareas en paralelo
  done; wait      # con  'wait'  esperamos a que finalizen todos los hilos
else
  echo -e "\n[*] Uso:  ./b01_portScan.sh <ip-address> \n"
  exit 1
fi
