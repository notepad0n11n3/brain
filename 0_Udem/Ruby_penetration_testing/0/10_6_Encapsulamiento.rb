
class Persona

  def hablar
    puts "Hola soy Pedro"
  end

  def gritar_fuerte
    puts gritar + " Soy Pedro.."
  end


  private     # solo funciona desde aqu[i dentro

  def gritar
    "Hellooo....!!!!"
  end

  protected   # D[esde fuera se comporta como private y desde dentro public   self.  <<--
  def self.saludo   # self.   apunta el objecto, protected desde dentro seComporta like public
    puts "Hello, how are you?"
  end
end
yo = Persona.new
yo.hablar
yo.gritar_fuerte

class Yo < Persona
  def saludando
    Persona.saludo
  end
end
puts "----------------------"
me = Yo.new
me.saludando

