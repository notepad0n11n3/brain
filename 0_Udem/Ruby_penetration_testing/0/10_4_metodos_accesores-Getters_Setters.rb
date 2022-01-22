
class Profesor
  def initialize(nombre)
    @nombre = nombre
  end

  def get_nombre
    @nombre
  end

  def set_nombre(nombre)
    @nombre = nombre
  end
end

pedro = Profesor.new("Pedro")
pedro.set_nombre("Manolo")
puts pedro.get_nombre


class Pros
  #attr_accessor  -  Setter y Getter
  #attr_reader    -  Getter
  #attr_writer    -  Setter
  attr_accessor :nombre, :edad

  def initialize(nombre, edad)
    @nombre = nombre
    @edad = edad
  end
end
manolo = Pros.new('Manolo',88)
manolo.nombre = "Siiuu"
manolo.edad = 888
puts manolo.nombre
puts manolo.edad








=begin
class Prosor
  def initialize(nombre)
    @nombre = nombre
  end

  def nombre
    @nombre
  end

  def nombre=(nombre)
    @nombre = nombre
  end
end


puts "----------------------"
marco = Prosor.new('Marco')
puts marco.nombre
=end
