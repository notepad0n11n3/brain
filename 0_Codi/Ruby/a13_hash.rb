
tutor = {"nombre" => "Uriel", "edad" => 23, 20 => "Veinte", [] => "arregloDes"}
puts tutor

tutor.each do |clave, valor|
  puts "En La clave: #{clave} ,esta guardado el valor: #{valor}"
end

puts tutor["nombre"]
puts tutor[[]]

tutor["cursos"] = 10
tutor["user"] = "panda8hat"

puts tutor["cursos"]
puts tutor[9]  # posicion 17  si no hay nada return nul (linea en blanco "\n")

tutor.default = ":)"
puts tutor[9]  # posicion 17  si no hay nada return nul (linea en blanco "\n")

# SYMBOLOS
puts "----------------------"
#
tutor2 = {nombre: "Uriel", edad: "23", cursos: 10}

puts tutor2
puts tutor2[:nombre]

tutor2.each do |clave, valor|
  puts "En #{clave} esta guardado #{valor}"
end
