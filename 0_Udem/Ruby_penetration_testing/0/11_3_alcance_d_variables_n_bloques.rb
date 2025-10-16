
def saludo
  yield
end

nombre = "Manolo"

saludo {puts "Hola #{nombre}"}

saludo do
  nombre = "wowowo"
  puts "Hello #{nombre}"
end
puts " - - - - "
puts nombre  # el cambio perciste fuera del bloque OJO  <<==


def despedida
  yield('hghghghghghg') # <<==  PASAMOS ARGUMENTO A NUESTRO BLOQUE
end

despedida do |nombre|    # <<== VALOR OBTENIDO POR YIELD('')
  puts "Hasta luego #{nombre}"
end

despedida do
  puts "Hasta luego #{nombre}"
end
