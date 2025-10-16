# el & crea un Proc,  el yield no

      #   YIELD ES MAS RAPIDO

def hola
  yield   # <<< <<--  permite recibir un bloque de codigo y ejecutarlo :)
end

hola do
  puts "Hello hello"
end
puts "--------------------------------------------"
def hola2
  yield if block_given? # si el bloque de codigoRecibido esta vacio no salta el error 
                        #   no tiene ningun bloque de codigo a ejecutar
  #   if block_given?   # return true si recibe algun bloque y false si no recibe nada
  #         yield solo se ejecuta si block_given? return true :)
end

hola2()
hola2 { puts "Hello hello block_given? :)"}
puts "--------------------------------------------"

def hola3 &bloqueDes
  otro_hola(&bloqueDes)
end

def otro_hola &block
  puts "Mandando a llamar desde otro_hola"
  block.call
end

hola3 do            #  hola3 { puts "u.u u.u u.u" }
  puts "u.u u.u u.u"
end
