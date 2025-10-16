

calificaciones = %w[10 7 8 9 5 8 10]


puts calificaciones * 3


puts calificaciones * "-"  # es un join

puts calificaciones.join(",")
puts calificaciones.join("-")
puts calificaciones.join(" # ")
puts calificaciones.join("").class.name


numbers = [10, 7, 8, 9, 5, 8, 10]

puts numbers.sort
puts numbers.reverse  # mostrar al revez el arreglo

puts numbers.include?(10)   # busca si existe 10 dentro del arreglo
puts numbers.include?(6)
numbers << "panda8hat"
puts numbers.include?("panda8hat")

puts numbers.first
puts numbers.last

puts numbers.uniq     # no elementos repetidos

puts numbers.sample     # elemento aleatorio del arreglo


puts (0..20).max
puts (0..20).min
