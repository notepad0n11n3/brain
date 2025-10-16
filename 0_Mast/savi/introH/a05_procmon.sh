#!/bin/bash
  # una forma cutre de ver un proceso cron en ejecuci[on

#traemos los procesos ejecutandoce
old_process=$(ps -eo command)

while true; do
  #traemoms AGAIN los procesos ejecutandose
  new_process=$(ps -eo command)
   # diff archivo1 archivo2     # muestra las diferencias entre los archivos
  diff <(echo "${old_process}") <(echo "${new_process}") | grep "[\>\<]" | grep -v "kworker"
  old_process=${new_process}
done
