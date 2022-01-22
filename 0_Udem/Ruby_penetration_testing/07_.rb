require 'digest'

def md5(password, diccionario)
  diccionario = diccionario.split("\n") # corta por salto de linea del archivo.txt

  diccionario.each do |value|
    cifrado = Digest::MD5.hexdigest value

    if cifrado == password
      return value
      break
    end
  end
end

def sha1(password, diccionario)
  diccionario = diccionario.split("\n")
  diccionario.each do |value|
    cifrado = Digest::SHA1.hexdigest value
    
    if cifrado == password
      return value
      break
    end
  end
end 

def sha256(password, diccionario)
  diccionario = diccionario.split("\n")
  diccionario.each do |value|
    cifrado = Digest::SHA256.hexdigest value
    if cifrado == password
      return value
      break
    end
  end
end

def sha512(password, diccionario)
  diccionario = diccionario.split("\n")
  diccionario.each do |value|
    cifrado = Digest::SHA512.hexdigest value
    if cifrado == password
      return value
      break
    end
  end
end

def menu
  puts ".. <===> .."
  puts " Ingresa el hash para determinar que tipo es y cual es su valor"

  password = gets.chomp

  diccionario = File.new('07_.txt', 'r')  # 'r'  <== read
  diccionario = diccionario.read

  case password.length
  when 32
    puts "El hash es MD5"
    puts "El valor es #{md5(password, diccionario)} "
  when 40
    puts "El hash es SHA1"
    puts "El valor es #{sha1(password, diccionario)} "
  when 64
    puts "El hash es SHA256"
    puts "El valor es #{sha256(password, diccionario)} "
  when 128
    puts "El hash es SHA512"
    puts "El valor es #{sha512(password, diccionario)} "
  else
    puts "No se pudo identificar el tipo de cifrado"
  end
end

menu
