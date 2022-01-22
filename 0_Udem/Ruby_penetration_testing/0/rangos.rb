#!/usr/bin/ruby


numeros=(1..20).to_a    # de rango a array

numeros.each do |x89p|
  puts "#{x89p}"
end

puts numeros.class
print numeros

puts "--------------------------------------------"

numeros=(1..20).step(3)
numeros.each do |x89p|
  puts x89p
end

abecedario=('a'..'z').to_a
abecedario.each do |i|
  puts i
end
puts abecedario.reverse

silabas=('ma'..'op').step(10)
silabas.each do |i|
  puts i
end
