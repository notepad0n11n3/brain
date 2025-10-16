#!/usr/bin/ruby


print "print 1", "print 2", "print 3", "print 4", "print 5"
puts "puts 1", "puts 2", "puts 3", "puts 4", "puts 5"

puts "--------------------------------------------"

print "  0-4 ==> "
user_data=gets.chomp.to_i

puts case user_data
when 1
  "\n\t Option One Ready..."
when 2
  "\n\t Option Two Ready..."
when 3
  "\n\t Option Tree Ready..."
when 4
  "\n\t Option Four Ready..."
else
  "\n\n\t\t\tU.U\tU.U\tU.U\t"
end

