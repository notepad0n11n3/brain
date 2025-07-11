#!/usr/bin/env python3

for i in range(5):
	print(i)

print("------------")

e = 0

while e < 10:
	if e ==  8:
		break
	print(e)
	e = e + 1

print("-----------------")

name = ["Test01", "Test02", "Test03", "Test04", "Test05"]


for i in name:
	print(i)

print("------------")

for i, nombre in enumerate(name):
	print(f"Number-: {i} ; Nombre-: {nombre}")

frutas = {"manzanas": 1, "platanos": 5, "kiwis": 3}							 # {} - Diccionarios con { "valorHere": claveUnicaINT }

for fruta, cantidad in frutas.items():
	print(f"Hay {cantidad} de la fruta {fruta}")
