#!/usr/bin/ruby

# ::: ruby 03_escaner_de_puertos.rb portHere ipHere
require 'socket'

# MAYUSCULAS PARA UNA CONSTANTE/VARIABLEconVALORfijo    ocupa menos memoria 
PORT = ARGV[0] || 80    # o coje el argumentos o usa por defecto el 80
HOST = ARGV[1] || 'localhost'

begin 
  socket = TCPSocket.new(HOST, PORT)
  status = "abierto"
rescue Errno::ECONNREFUSED, Errno::ETIMEDOUT
  status = "cerrado"
end

puts "Puerto: #{PORT} esta => #{status}"
