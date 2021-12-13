
#     SON FUNCIONES SIN NOMBRE

#  lambda {puts "Hello Hello"}.call

miLambdaDes = lambda {puts "Hola mundo"}
miLambdaDes.call

#mLambdaDes = ->()  {puts "Hello hello hello"}
#mLambdaDes.call

lambdaGoro = ->(argumento1) {puts "Hola #{argumento1}"}
lambdaGoro.call("argumento <3")

puts lambdaGoro.class.name

puts "---------------------------------"

def test_lambda
  (->() {return "Game Over lambda"}).call()
  puts "Despues de la lambda"
end

def test_block
  (Proc.new { return "Game Over block"}).call()
  puts "Despues del bloque"
end

puts test_lambda
puts test_block
