
#  ES UNA CADENA INMUTABLE   like a una constante

test1 = "uriel"
test1.capitalize!
puts test1

cadena = "Uriel"

cadena2 = "Uriel"

simbolo = :Uriel

simbolo2 = :Uriel

# object_id    Numero que identifica a un objeto dentro de ruby
#       todos los objetos tienen diferente object_id incluso si tienene el mismo valoe
#           EXCEPTO los simbolos, si 2 simbolos tienen l mismo tienen object_id iguales

puts cadena.object_id
puts cadena2.object_id

puts simbolo.object_id
puts simbolo2.object_id

