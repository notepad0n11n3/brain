def hola_gente(personas)
  personas.each {|persona| puts "Hola #{persona}"}
end

hola_gente(["Uriel", "Coco"])



def goro(mensaje, *personas) #El operador splat *  recibe todos los argumentos dentro de un argumento :)
  # Personas es un arreglo
  personas.each {|persona| puts "#{mensaje} #{persona}"}
end


goro "Hello des", 10, "8","medusa", "Coco", ":)", ":(", 23, 24

#---------------------------------
puts "--------------------------------------------"
#

test = ["Uriel", "Coco", 8, 10, 22, "3", ":(", ":)"]

goro "Test hello...", test

goro "u.u test con splat, *test...", *test    # <<<<----
