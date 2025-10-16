


print "Date tu calificacion (1-10): "
calificacion = gets.chomp.to_i

case calificacion
when 10,9
  puts "Muy bien...."
when 8
  puts "Aun puedes mejorar"
when 7
  puts "Sabemos que lo puedes hacer mejor"
else
  puts "u.u"
end

puts case calificacion
when 10,9
  "Muy bien...."
when 8
  "Aun puedes mejorar"
when 7
  "Sabemos que lo puedes hacer mejor"
else
  "u.u"
end



#if calificacion == 10 || calificacion == 9
#  puts "Muy biieenn..."
#elsif calificacion == 8
#  puts "Bien pero puedes mejorar..."
#elsif calificacion == 7
#  puts "Sabemos que lo puedes hacer mejor"
#elsif calificacion == 6
#  puts "No estas horriblemente mal, pero casi :("
#else
#  puts "u.u"
#end
