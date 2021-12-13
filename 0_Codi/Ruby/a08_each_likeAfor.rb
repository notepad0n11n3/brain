


# Ciclo each

calificaciones = %w[ 10 7 8 9 5 9] # #todo string y sin , Ciclo  :)


suma = 0

calificaciones.each do |x89p|
  puts "Ahora calificacion vale: #{x89p}"
end

calificaciones.each_with_index do |panda8hat,aeo8|
  puts "En la posicion #{aeo8} tenemos: #{panda8hat}"
end

calificaciones.each_with_index do |calificacion,posicion|
  suma += calificacion.to_i
end

puts "El promedio de tus calificaciones es #{suma / calificaciones.length}"
                            # la operacion para el promedio dentro de #{} no da problemas <3
