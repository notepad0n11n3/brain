def saludo(nombre:"",edad:0,country:"Peru")
  if edad > 40
    puts "Buenas tardes se~or #{nombre}"
  else 
    puts "Hola joven #{nombre}"
  end
  puts country
end

saludo(nombre:"wowoo",edad:30)
saludo(nombre:"fufuu",edad:30,country:"japan")


## Hallar el area de un circulo
#   pi*r**2
#   pi = 3.1416

def circulo(radio:1)
  pi = 3.1416
  return pi*radio**2
end

puts circulo(radio:5)
