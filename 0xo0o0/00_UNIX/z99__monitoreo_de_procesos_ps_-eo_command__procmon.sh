#!/bin/bash 

# Monitorea los comandos ejecutados en el sistema, y cron esta ejecutando algo lo vamos a poder ver... <3 <3 <3

function ctrl_c(){
	echo -e "\xA\xA[!] Saliendo...\xA"
	tput cnorm; exit 1
}

trap ctrl_c INT

tput civis

old_process="$(ps -eo command)"

while true; do
	new_process="$(ps -eo command)"
	diff <(echo "${old_process}") <(echo "${new_process}") | grep "[\>\<]" | grep -vE "command|procmon|kworker"
	#																																												procmon == nombre del archivo sin extension ".sh"
	old_process=${new_process}
done
