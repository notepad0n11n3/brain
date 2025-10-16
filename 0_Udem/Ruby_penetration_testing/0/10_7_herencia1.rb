
class Persona
  attr_accessor :nombre, :edad

  def saludar
    puts "Hello, i am #{nombre}"
  end
end

class Doctor < Persona
  attr_accessor :codigo

  def recetar
    puts "doctor here... "
  end
end
manolo = Persona.new
manolo.nombre = "Monolo"
manolo.saludar

marco = Doctor.new
marco.codigo = 888
marco.nombre = "Marco"
marco.saludar
puts marco.codigo
