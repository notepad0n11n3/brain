
class Video
  @@type = "video/mp4"

  def self.type_claseDes   #  M[etodo para la clase
    puts @@type
  end

  def type_objetoDes       #  M[etodo para el objeto
    puts @@type
  end
end

nuevo_video = Video.new
nuevo_video.type_objetoDes
puts "--------------------------------------------"
Video.type_claseDes


###       LAS CLASES HIJAS SOLO HEREDAN LAS VARIABLES DE CLASE
class Padre
  @@variable_de_clase = "Test de la clase..."
  @variable_de_objeto = "Test de el objeto..."

  def self.test
    puts @@variable_de_clase
    puts @variable_de_objeto
  end
end

class Hija < Padre   ## LAS CLASES HIJAS SOLO HEREDAN LAS VARIABLES DE CLASE

  ###  ni sobreescribiendo la funcion y usando super la variable de objeto baja :'u
  def self.test
    super
  end
end

puts "", ""
Padre.test
Hija.test
