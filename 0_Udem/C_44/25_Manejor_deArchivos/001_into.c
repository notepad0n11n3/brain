

        Par[ametro                  Significa abrir el archivo en modo

            r           Lectura.     El archivo debe existir.
            w           Escritura.     Si el archivo no existe, se crea, si existe, se sobrescribe.
            a           Escritura al final del documento.     Si no existe se crea.
            rb          Binario.     Para lectura.

            r+          Lectura y Escritura.     El archivo debe existir.
            w+          Crear un archivo para Escritura.     Si existe se sobrescribe.
            rb+         Binario.     Para actualizaci[on (lectura y escritura)


  fputsc(Caracter, ApuntadorArchivo)   es una funci[on, nos permite escribir un caracter en el archivo, regresa el caracter que se presion[o en caso de que la operaci[on se realice con [exito o EOF si fallo.
                                      El apuntador es el que nos brinda la funci[on fopen.

  fclose(ApuntadorArchivo)   guarda los cambios en el archivo, cierra la conexi[on y libera los recursos usados por el apuntador.



            char mango;         char mango[];       char mango[8888];
            fputc('\n', apuntador_Archivo);  fputc(mango, apuntador);



            NOMBRE                     FUNCION

            fopen()             Abre un archivo.
            fclose()            Cierra un archivo.
            fgets()             Lee una cadena de un archivo.
            fputs()             Escribe una cadena en un archivo.
            fseek()             Busca un byte especifico de un archivo.
            fprintf()           Escribe una salida con formato en el archivo.
            fscanf()            una entrada con formato desde el archivo.
            feof()              Devuelve cierto si se llega al final del archivo.
            ferror()            Devuelve Cierto si se produce un error.
            rewind()            Coloca el localizador de posici[on del archivo al principio del mismo.
            remove()            Borra un archivo.
            fflush()            Vacia un archivo.


          MODO                    SIGNIFICADO
          r                 Abre un archivo de texto para lectura
          w                 Crea un archivo de texto para escritura // si existe, se sobrescribe. no testeado
          a                 Abre o Crea un archivo de texto para a;adir

          rb                Abre un archivo BINARIO para lectura
          wb                Crea un archivo BINARIO para escritura
          ab                Abre un archivo BINARIO para a;adir

          r+                Abre un archivo de texto para lectura/escritura
          w+                Crea un archivo de texto para lectura/escritura
          a+                A~ade o Crea un archivo de texto para lectura/escritura

          r+b               Abre un archivo BINARIO para lectura/escritura
          w+b               Crea un archivo BINARIO para lectura/escritura
          a+b               A~ade o Crea un archivo BINARIO para lectura/escritura
