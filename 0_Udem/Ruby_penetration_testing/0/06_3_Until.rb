
#Ingresar password
#3 intentors

puts "Ingresa el password"
print "=> "

mis_pass = gets.chomp
password = "helloworld"
intentos = 0

until mis_pass.downcase == password 
  puts "\n\t\t Passowrd INCORRECTA...!!!"
  puts "\n\t\t Ingresa el password nuevamente:...#{intentos} restantes :( "
  print "\n\t\t => "
  mis_pass=gets.chomp

  intentos += 1
end

x89p=0
until !(x89p < 3) || false
  print "\n    if<==>unless      while<==>until"
  x89p += 1
end
