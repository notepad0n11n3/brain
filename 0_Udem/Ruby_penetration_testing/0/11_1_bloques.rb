

[1,2,3,4,5,6,7,8,9].each do |number|
  puts number
end
puts "--------------------------------------------"
(1..9).each {|number| puts number}


[1,2,3,4].each_with_index do |numberDes, positionDes| # .each_with_index ESunMETODO, NO SE PUEDE AGREGAR DES :'u
  puts "N[umero #{numberDes} => posicionArray #{positionDes}"
end



paresDes = [1,2,3,4,5,6,7,8,9].select do |numberMe|
  numberMe%2 == 0
end
puts paresDes
puts "--------------------------------------------"

imparesDes = [1,2,3,4,5,6,7,8,9].select {|numberDes| numberDes%2 != 0}
puts imparesDes
