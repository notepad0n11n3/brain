
# get like a input scanf read etc...
# chomp  elimina el ultimo caracter( \n )
# to_i        a entero

puts "Ingrese edad"
edad_user=gets.chomp.to_i

puts "Ingrese el limite"
limite_user=gets.chomp.to_i

if edad_user < limite_user
  puts "Menor de Edad, #{edad_user}"
elsif edad_user > limite_user
  puts "Mayor de Edad, #{edad_user}"
else
  puts " Else rolling :), #{edad_user} #{limite_user} "
end


puts "----------------------"

unless false
  puts "Inverso a if, si es falso entra en la sentencia"
end

puts "solo para una condicion" unless 1 < 1  #no else ni elsif PLS

puts "----------------------"


  # ES MEJOR USAR UNLESS  BUENAS PRACTICAS MEN :U
unless edad_user > limite_user
  puts "No eres mayor de edad, no puedes pasar :u "
end

if !(edad_user > limite_user)
  puts "No eres mayor de edad, no puedes pasar :u "
end



