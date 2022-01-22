
class Perro
  def initialize(razaIni:"", nombreIni:"")
    @raza = razaIni
    @nombre = nombreIni
  end

  def saludar
    puts "Hola soy #{@nombre} y soy de raza #{@raza}"
  end
end


perro1 = Perro.new(nombreIni:"Panda",razaIni:"peruano")


if perro1.respond_to?("correr")
  perro1.correr
else
  puts "Lo siento, el objeto no entiende el metodo .correr"
end

if perro1.respond_to?("saludar")
  perro1.saludar
else
  puts "Lo siento, el objeto no entiende el metodo .saludar"
end

perro2 = perro1
puts "----------------------"
perro2.saludar
