#!/usr/bin/ruby

frase = "Manguito liquado con leche es una delicia, Manguito uma delicia U.U"
frase = frase.sub("Manguito", "Fresa")   # SOLO REMPLAZA LA PRIMER COINCIDENCIA
puts frase

puts ""

frase = frase.gsub("Manguito", "Fresa") # REMPLAZA TODAS LAS COINCIDENCIAS
puts frase


saludo = "hello little witch"

saludo2 = saludo.sub(/^...../,"My") # 5 . para remplazar el hello, raro, lo s[e, cre[i que ser[ian 4 .  :'u
puts saludo2

saludo = saludo.sub(/^./,"4") # .    un caracter cualquiera
puts saludo


weird = "texto gen[erico de prueba"
weird= weird.scan(/.../) {|i| puts i} #cualquier valor de 3 en 3,  no sale a, solo puts de 3 en 3

weird=weird.scan(/\S\S\S/) {|i| puts i} #cualquier valor de 3 n 3 MENOS ESPACIOS...!!!


newnew="expresiones regulares con n[umeros 10101010"
newnew=newnew.scan(/\d/) {|i| puts i}
newnew=newnew.scan(/\d+/) {|i| puts i}  # puts i concatenados

newnew=newnew.scan(/[eoa]/) {|i| puts i}
newnew=newnew.scan(/[a-m]/) {|i| puts i}
