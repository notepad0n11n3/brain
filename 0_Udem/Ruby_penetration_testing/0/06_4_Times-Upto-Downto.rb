
print "Ingresa un N[umero: "

numero=gets.chomp.to_i
suma=0

numero.times do |i|
  puts i
end


=begin        ## comentario de varias lineas
# 100.times do |x89p|
#   puts x89p
# end
#
# 10.upto(12) do |i|
#   puts i
#         ##  10  11  12
# end
#
# 12.downro(10) do |i|
#   puts i
# end
#
=end          ## comentario de varias lineas

print "Ingresar el valor minimo: "
min_user=gets.chomp.to_i
print "Ingresar el valor m[aximo: "
max_user=gets.chomp.to_i

suma=0

min_user.upto(max_user) do |i|
  puts i
end

