

tutor = {nombre: "Uriel", edad: "23", cursos: 10}


puts tutor.length
puts tutor.size     # igual al lenght

puts "--------"
puts tutor.keys    # devuelve todas las claves
puts "--------"
puts tutor.values
puts "--------"

puts tutor.has_key?(:nombre) # return True
puts tutor.has_key?(:goro)   # return False

puts tutor.has_value?("23")  # return True si el valor exciste

#tutor.clear       # eliminar todos los elementos del hash
tutor.delete(:cursos) # elimina clave y valor 

puts tutor

puts tutor.key("Uriel")   # obtener la clave usando el valor


user_info = {apellido: "Hernande", segundo_apellido: "Camacho"}
puts "--------"
puts tutor.merge(user_info) # une los 2 hashes
