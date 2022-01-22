#!/usr/bin/ruby

booleano=true
cadena_texto="Soy un String"
numero=5
flotante=7.2
arregloDes=["Hello", "bye"]

arrayGoro=["arreglo goo", 8, false, cadena_texto, numero, arregloDes, flotante]

puts arrayGoro
puts arrayGoro[1]
puts "============================================"

arrayGoro[1]=888
puts arrayGoro.size
puts arrayGoro.length

x89p=arrayGoro.length
arrayGoro[x89p]="Panda8hat"

puts arrayGoro[-1]
puts arrayGoro.length
puts arrayGoro.size

puts "============================================"

arreglo_puro_strings=%w[todo esto es un array de strings, no necesito comas <3]
#puts arreglo_puro_strings
print arreglo_puro_strings

cadenDes="hello"
puts cadenDes[1]
