
def hola
  yield                #     <<<<======<<<====...!!!
end

hola {puts "Hola"}

hola do
  suma = 1 + 1000
  puts suma
end

puts "--------------------------------------------"
def adios
  yield if block_given?  #si no pasamos un bloque de codigo no lanza error de sintaxis
end

adios 
adios {}


def saludo nombre,&bloqueDes #el bloque SIEMPRE esEl [ultimo parametro del metodo/funci[on
  puts bloqueDes.call
  puts nombre

  puts ""

  qpqp=bloqueDes.call
  puts qpqp + " " + nombre
end

saludo ('manolo') {"Good Morning"} #{puts "Good Morning"}
