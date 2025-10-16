#!/usr/bin/python3   
#coding: utf-8

        #!!!!!    ::: echo $PATH 
        #!!!!!    ::: sudo mv wihchSystem.py /usr/bin

import re, sys, subprocess

    ###  re ==> librer[ia re, para el manejo de expresiones regulares
    ###  sys => tener control o controlar el n[umero de argumentos que se le pasan al programa, sirve tambi[en para usar salida exitosa o erronea en consola
    ###  subprocess ==>  al ejecutar el programa quiero lanzar un subproceso que me haga una traza icmp a la maquina victima, despues conseguir el ttl por expresiones regulares(re)


# python3 whichSystem.py 10.10.10.188

validIp = sys.argv[1]
print('El validIp es ' + validIp + 'goro goro dess...')
if len(sys.argv[1]) != re("\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}")
    print('goroDess...')

if len(sys.argv) != 2:  ##  python3 whichSystem.py ipHere     ## Los argumentos son diferentes que 2 (0,1,2)  no toy seguro :(
                        ##    0          1           2           
    print("\n\t [!] Uso: python3 " + sys.argv[0] + " <direcci[on-ip> \n")  
    sys.exit(1) #si no salimos se va al main :u    0 salidaExitosa  !0 error

def get_ttl(ip_address):

    proc = subprocess.Popen(["/usr/bin/ping -c 1 %s" % ip_address, ""], stdout=subprocess.PIPE, shell=True) #despu[es de ip_address agregamos "" por la sintaxis de subprocess, si no da error
    #   %s  ==>  string cadenaTexto
    #   subprocess.Popen()   ==>> genera un subproceso
    #   stdout=subprocess.PIPE    ==> variable stdout almacenando el output del subproceso.PIPE
    #   shell=True  ==>  y todo eso lo quiero emitir desde una consoleShell
    
    (out,err) = proc.communicate()   #creamos las variables out y err para almacenar los stdr  errores

    out = out.split()
    #  print(out[12]) ## si no se pone nada 'print(out)' muestra todo dividido por ',' , funciona como un array :) ,   out[12]  lugar del ttl <3
    out = out[12].decode('utf-8')  # al realizar ' print( type( out[12] ) )'  salia una b y comas, era un tipo de variable <class 'bytes'>
                #decode('utf-8')  ==>> pasando a stirng el <class 'bytes'>      now <class 'str'>
    ttl_value = re.findall(r"\d{1,3}", out)[0]  # expresiones regulares  !!!  'out'  es la variable que estamos usando, no es para cerrar algo
    #print(ttl_value)  ## ['64']  con [0] mostramos el primer elemento [0]  01234etc

    return ttl_value

def get_os(ttl):
    #print(type(ttl))  # ttl es string :u
    ttl = int(ttl) #convertimos ttlString a ttlEntero
    #print(type(ttl))
    if ttl >= 1 and ttl <= 64:
        return "Linux"
    elif ttl >= 65 and ttl <= 128:
        return "Windows"
    else:
        return "Not Found"


if __name__ == '__main__':

    a = sys.argv[0]
    b = sys.argv[1]
    print(a + ' == printa')
    print(b + ' == printb')

    ip_address = sys.argv[1]

    ttl = get_ttl(ip_address)   

    os_name = get_os(ttl)

    print("%s (ttl => %s): %s" % ( ip_address, ttl, os_name))
        #192.168.0.24 (ttl => 64): Linux
        #   string      texto str   string      todo variables
