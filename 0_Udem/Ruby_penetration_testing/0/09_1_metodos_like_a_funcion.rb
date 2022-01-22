

def saludo(nombreDes)
  puts "Hello #{nombreDes} U.U"
end

saludo('medusa')


def suma(a,b)
  a+b       # like a      return a+b
end

def resta(a,b)
  a-b
end

def mul(a,b)
  a*b
end

def div(a,b)
  a/b
end

def pot(a,b)
  a**b
end

puts (".....: Funny day with ruby U.U ")
print("Ingresa el primer n[umero => ")
numero1=gets.chomp.to_i

print("Ingresa el segundo n[umero => ")
numero2=gets.chomp.to_i

puts("Ingresa el modo")
puts("[1]. Suma", "[2]. Resta", "[3]. Multiplicaci[on", "[4]. Divisi[on", "[5]. Potencia")
option_user=gets.chomp.to_i

puts case option_user
when 1
  suma(numero1, numero2)
when 2
  resta(numero1, numero2)
when 3
  mul(numero1, numero2)
when 4
  div(numero1, numero2)
when 5
  pot(numero1, numero2)
else
  puts "\n\t\t... Opci[on incorrecta...\n\t\t\t......Saliendo..."
end
