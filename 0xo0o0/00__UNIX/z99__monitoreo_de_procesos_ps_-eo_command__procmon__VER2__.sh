#!/bin/bash 

# Monitorea los comandos ejecutados en el sistema, y cron esta ejecutando algo lo vamos a poder ver... <3 <3 <3

old_process="$(ps -eo user,command)"

while true; do
	new_process="$(ps -eo user,command)"
	diff <(echo "${old_process}") <(echo "${new_process}") | grep "[\>\<]" | grep -v "kworker"
	old_process=${new_process}
done
