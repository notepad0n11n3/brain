#!/bin/bash

for goroDes in $( seq 2 254 ); do
  timeout 1 bash -c "ping -c 1 192.168.0.${goroDes} > /dev/null 2>&1" && echo " Host 192.168.0.${goroDes} == ACTIVE " &   # con & ejecutamos por hilos 
done; wait     # con  'wait'  esperamos a que finalizen todos los hilos
