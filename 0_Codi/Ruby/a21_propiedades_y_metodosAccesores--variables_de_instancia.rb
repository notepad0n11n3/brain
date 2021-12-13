    # son como variables localesDentro de la definicion del objeto
#         solo pueden ser modificadas desde dentro de la definicion 
class Tutor
  def initialize(name)
    @nombre = name
#    puts @nombre
  end

  def say_may_name
    puts @nombre
  end
end

uriel = Tutor.new("Uriel")
jose = Tutor.new("Jose")

uriel.say_may_name
jose.say_may_name


puts "---------------------------------"

class Goro
  def initialize(name)
    @nombre = name
  end
  # { METODOS ACCESORES
  def getDes_nombre
    return @nombre
  end
  
  def setDes_nombre(nombre)  # ===  def setDes_nombre=(nombre)
    return @nombre = nombre
  end
  #   METODOS ACCESORES }

end

kali = Goro.new("One")
parrot = Goro.new("Two")

puts kali.getDes_nombre
puts parrot.getDes_nombre

puts "Bautiza a One"
new_kali=gets.chomp
kali.setDes_nombre(new_kali)

parrot.setDes_nombre("Segundo")

puts kali.getDes_nombre
puts parrot.getDes_nombre

puts "---------------------------------"

class Goro2
  #{  METODOS ACCESORES
  attr_accessor :nombre  # solo define getDes_Nombre   setDes_nombre 
  attr_reader :nombre   # solo define el getDes_nombre
  attr_writer :nombre   # solo define el setDes_nombre
  #   METODOS ACCESORES }
  def initialize(x89p)
    @nombre = x89p
  end
end

owo = Goro2.new("Test1")
umu = Goro2.new("Test2")

puts owo.nombre
owo.nombre = "faiar... new test1"
puts owo.nombre
puts umu.nombre
