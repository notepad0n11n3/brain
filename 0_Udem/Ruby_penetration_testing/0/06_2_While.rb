#!/usr/bin/ruby

contador=0
while contador < 3
  puts "El contador esta en #{contador}"
  contador += 1
end


puts "Ingresa tu password"
print " => "
pass_user=""
password="panda8hat"

intentos_pass=0
while (pass_user.downcase != password) && (intentos_pass < 2)
  puts "...You password is"
  print " => "
  pass_user=gets.chomp
  intentos_pass += 1
  if pass_user == password
    puts "\n\n\t\t Welcome back again x89p "
  elsif
    puts "Invalid password, try again please..."
  end
end

