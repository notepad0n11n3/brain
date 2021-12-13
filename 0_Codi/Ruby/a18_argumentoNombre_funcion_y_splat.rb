
def hole(nombre:"", edad:0, **options)
#def home(nombre:, apellido:) nombre y pellido obligatorios, noTienen valorDefault ""
  if edad > 30
    puts "Hola se~or #{nombre}"
  elsif edad < 30
    puts "Hola joven #{nombre}"
  end

  puts options

  puts "---------------------------------"
  options.each do |des|
    puts "#{des}"
  end
  puts options[:color_favorito]
  puts options[:animal_favorito]
  
end


hole(edad:29, nombre:"x89p", color_favorito:"Celeste", animal_favorito:"virus")
