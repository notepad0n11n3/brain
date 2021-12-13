
class Usuario
  attr_accessor :nombre

  def saludar
#    yield(@nombre)
    saludo = yield(@nombre)
    puts saludo
  end

end

uriel = Usuario.new

uriel.nombre = "Uriel"

#uriel.saludar { |argumento1| puts "Hola #{argumento1}"}
#uriel.saludar { |argumen1| puts "Hello #{argumen1}"}

uriel.saludar { |argumento1| "Hola #{argumento1}"}
uriel.saludar do |argumen1| 
  "Hello #{argumen1}"
end
