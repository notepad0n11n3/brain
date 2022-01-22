
class Humano
  attr_accessor :nombre, :edad, :genero
  
  def initialize(name, years, genre)
    @nombre = name
    @edad = years
    @genero = genre
  end

  def saludo
    puts "Hello, my name is #{nombre}"
  end
end

manolo = Humano.new("Manolo", 88, "Masculino")
marco = Humano.new("Marco", 88, "Masculino")
krystal = Humano.new("Krystal", 88, "Femenino")

puts manolo.nombre, manolo.edad, manolo.genero
puts marco.nombre, marco.edad, marco.genero
puts krystal.nombre, krystal.edad, krystal.genero

krystal.nombre = "LiSA"
krystal.saludo


