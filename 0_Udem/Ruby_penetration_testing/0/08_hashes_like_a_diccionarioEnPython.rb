mangoTest='kintaro'
hashesDes = {'nombre'=> mangoTest, 'apellido' => 'oeh', :edad => 24, :preferencias => ['rojo', 'azul']}

puts hashesDes['nombre']

print "\n ---------------------- \n"
hashesDes.each do |i|
  puts i
end

print "\n ---------------------- \n"
hashesDes.each do |claveDes, valorDes|
  puts "La propiedad #{claveDes} tiene como valor #{valorDes}"
end
