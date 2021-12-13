

    #  EL BLOQUE RECIBE LAS VARIABLES LOCALES DE DONDE SE ESTA EJECUTANDO ...!!!
def hola
  yield
end

nombre = "Uriel"

hola { puts "Hola #{nombre}"}

hola do
  nombre = "Marcos"
  puts "Hola #{nombre}"
end

puts nombre    # LA VARIABLE NOMBRE QUEDA MODIFICADA DESPUES DE LA EJECUTION DEL BLOQUE

hola do |argument1, argumento2 ; varLocalBloque1, varLocalBloque2|
  nombre = "varLocalBloque"
  puts "Hello varLocalBloque #{nombre}"
end

puts "--------------------------------------------"

def hola2
  yield("Uriel")
end

hola2 do |nombreDes|
  puts "Hola #{nombreDes}"
end

#puts nombreDes    # la argumentos nombreDes solo existe dento del bloque 
