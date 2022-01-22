#!/usr/bin/ruby

puts "Ingresa un nuemro"
print "=>"
numero = gets.chomp.to_i

#if numero%2 == 0
#  puts "El n[umero es par"
#else
#  puts "El n[umero es impar"
#end


puts numero%2 == 0? "El n[umero es par" : "El n[umero es impar"
