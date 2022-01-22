=begin
  hashes.length   .size   .delete(clave)    .empty?   .invert   .has_key?   .keys   .values   .key('valor')
        .clear    .merge(hashes2)
=end

goro = {'nombre' => 'kintaro', :apellido => 'oe', :edad => 30, :curso => 'Ruby'}

puts goro['nombre']
puts '--------'
puts goro[:nombre]
puts '* * * * * * *'
puts goro[:apellido]
puts '--------'
puts goro['apellido']

goro.default = "No existe esa clave"
puts goro['manolo']


puts " * "
goro.each do |claveDes, valorDes|
  puts "La clave #{claveDes} => tiene el valor #{valorDes}"
end

puts goro.length
puts goro.size

puts goro.has_key?(:apellido)
puts goro.has_key?(:lastname)

puts goro.keys;   puts "------"   
puts goro.values;   puts "--------"

puts goro.key("kintaro")

#goro.clear
#puts goro

goro.delete(:apellido)
puts goro
