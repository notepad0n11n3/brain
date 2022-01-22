
class Terricola
  attr_accessor :nombre

  def initialize(nombre)
    @nombre = nombre
  end

  def saludar
    puts "Hello, i'm a #{nombre} y soy un #{self.class}" # apunta a la propia clase (Terricola)
  end

end

class Ingeniero < Terricola
end

class Animal < Terricola
  def saludar
    puts "Soy un #{self.class} y por eso no hablo"
  end
end

class Lion < Animal
  def saludar
    puts 'GRRRRR...!!!'
  end
end

marco = Terricola.new("Marco")
marco.saludar
#puts marco.class  #  marco.class <==> Terricola

manolo = Ingeniero.new("Manolo")
manolo.saludar
#puts manolo.class  # manolo.class <==>  Ingeniero

dog = Animal.new('Dog')
dog.saludar

lion = Lion.new('Leon')
lion.saludar
