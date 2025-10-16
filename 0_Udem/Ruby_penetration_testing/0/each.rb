#!/usr/bin/ruby

user_data=[3, 0, 8]

user_data.each do |x89p|
  puts "objeto de array => #{x89p}"
end


ages_main=[10,11,22,45,60,88]
contador=0

ages_main.each do |x89p|
  contador += 1
  if x89p > 18
    puts " MAYOR de edad... => #{x89p}"
  else
    puts " Menor de edad... => #{x89p}"
  end
  puts contador
end

nombres=['Pedro', 'Robert', 'Ariana', 'Ana']

nombres.each do |x89p|
  if x89p[-1] == 'o'
    puts "Buenos d[ias SE;OR #{x89p}"
  elsif x89p[-1] == "a"
    puts "Buenos d[ias SE;ORITA #{x89p}"
  else
    puts "\t\tU.U\tU.U\tU.U\t"
  end
end
##          EXTRA EXTRA EXTRA EXTRA 

[1,2,3,4,5,6,7,8,9].each do |number|
  puts number
end
puts "--------------------------------------------"
(1..9).each {|number| puts number}


[1,2,3,4].each_with_index do |numberDes, positionDes| # .each_with_index ESunMETODO, NO SE PUEDE AGREGAR DES :'u
  puts "N[umero #{numberDes} => posicionArray #{positionDes}"
end
