def saludoOld(nombres)
  nombres.each do |wowo|
    puts "Hello #{wowo}"
  end
end

def saludo(nombres)
  nombres.each {|wowo| puts "Hello #{wowo}"}
end

#saludo(['manolo','marco'])
#saludoOld(['manolo','marco'])


amigos=['Juan','Manolo','Marco']
def saludoSplat(*nombresDes)  # el Splat '*'  aceptaTodo comoUn hash
  nombresDes.each do |wowo|
    puts "Hello #{wowo}"
  end
end

saludoSplat('Manolo','Angel','Marco')  #sin el operador Splat '*' mandaError
puts "----------------------"
saludoSplat(*amigos) # el Splat '*' desarma el hashArray por el splat en el parametro de la funcion :u
