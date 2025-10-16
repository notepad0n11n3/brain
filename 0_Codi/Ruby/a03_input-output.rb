


print("\t Dame tu nombre: ")

user_data=gets
user_data=user_data.chomp  # el metodo  .chomp elimina el [ultimo caracter (gets mete un saltoDeLinea al final \n)
                           # 

puts("Hello #{user_data}")
puts("\t Tu nombre tiene #{user_data.length} letras")
