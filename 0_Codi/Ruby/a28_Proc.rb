
#     un bloque no es un objeto en ruby, es parte de la sintaxis de la ejecucion de un metodo
#        LOS PROC SI SON OBJETOS Y PUEDN SER ALMACENADOS EN VARIALBES y pasados como argumento

def hola &block   # el & crea un Proc,  el yield no
  puts block.class.name
        # LOS PROC PUEDEN SER ALMACENADOS EN VARIABLES
  block.call      #BLOCK NO ES UN OBJECTO, ES UN  PROC
end

hola {puts "Yeepee"}


def hola2 proc1Des, proc2Des
  proc1Des.call
  proc2Des.call
end

proc1Des = Proc.new {puts "Hola proc1"}
proc2Des = Proc.new {puts "Hola proc2"}

hola2(proc1Des, proc2Des)
