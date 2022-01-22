require 'socket'

TIMEOUT = 2

### EL ASINCRONISMO DA PROBLEMAS,  MUESTRA QUE TODOS LOS PUERTOS ESTAN ABIERTOS  :U  una mrd csm

def scan_portDes(puerto)
  socket = Socket.new(:INET, :STREAM)
  ip = Socket.sockaddr_in(puerto, '127.0.0.1')   ### <<<===      Just here little one    IP TARGET
  begin
    socket.connect_nonblock(ip)
  rescue Errno::EINPROGRESS
  end

  _, sockets, _= IO.select(nil, [socket],nil, TIMEOUT)

  if sockets
    puts "Puerto #{puerto} abierto"
  else
    puts "Puerto #{puerto} cerrado"
  end
end

puertos = [21,22,23,53,443,3306,8080]
threads = []

puertos.each {|i| threads << Thread.new{scan_portDes(i)}}
threads.each(&:join)
