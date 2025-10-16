#!/usr/bin/ruby

puts " test switch ruby "
print "Ingresa una opcion 0-3: "
user_data=gets.chomp.to_i

if user_data > 3 || user_data <= 0
  print "\n\t\tIngresa una posici[on v[alida entre 0 y 3"
else
  case user_data
  when 3
    puts "\t option 3 Ready..."
  when 2
    puts "\t\t option 2 reAdy..."
  when 1
    puts "\toption\t 1 \t READY..."
  end
end
