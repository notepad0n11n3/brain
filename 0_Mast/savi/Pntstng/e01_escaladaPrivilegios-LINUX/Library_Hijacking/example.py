#!/usr/bin/python
                            #jugando con ruta relativa y absoluta

## EN PYTHON LAS LIBRERIAS SE PUEDEN OBTENER DESDE EL DIRECTORIO ACTUAL, suplantamso el hashlib original por uno creado en la carpeta actual :)  :)
                ##   El path tira del directorio actual de trabajo
import hashlib, sys

if len(sys.argv) >= 3:
    print ("Demasiados parametros ingresados :(")
    sys.exit(1)
    
if len(sys.argv) != 2:
    print ("Ha habido un error...\n")
    sys.exit(1)

if __name__ == '__main__':
    palabra = sys.argv[1]

    md5 = hashlib.md5(palabra).hexdigest()     # convertir una cadena a MD5

    print (md5)     # print el parametro como MD5
