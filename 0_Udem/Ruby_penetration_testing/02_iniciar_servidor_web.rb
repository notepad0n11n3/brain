#!/usr/bin/ruby

require 'webrick' # gem install webrick    si no lo tienes instalado <3

path = File.expand_path('/home/aeo8/Desktop/brain/0_Udem/Ruby_penetration_testing')
server = WEBrick::HTTPServer.new :Port => 8000, :DocumentRoot => path

trap 'INT' do server.shutdown end   # muestra los eventos(log/conexiones) en consola
server.start
