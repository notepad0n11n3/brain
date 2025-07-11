#!/usr/bin/env python3

edad = 20

mensaje = "Eres mayor de edad" if edad >= 18 else "Eres menor de edad"

print(mensaje)


numeros = [1,2,3,4,5]

resultado = ["par" if n % 2 == 0 else "impar" for n in numeros]

print(resultado)
