require 'matrix'
                                             #       --  --
matriz = Matrix[[1,2,3],[4,5,6],[7,8,9]]     #     | 1 2 3 |
                                             #     | 4 5 6 |
                                             #     | 7 8 9 |
                                             #       --  --

matriz.each do |i|
#  puts i
end

puts "--------"

matriz.each(:diagonal) do |i|
#  puts i
end

puts "--------"

matriz.each(:strict_upper) do |i|
#  puts i
end

puts "--------"

matriz.each(:strict_lower) do |i|
  puts i
end


puts matriz.diagonal?

matriz2 = Matrix[[1,0,0],[0,2,0],[0,0,3]]
puts matriz2.diagonal?
