#!/usr/bin/env python3

# Bucles Anidados

my_list = [[1,4,5], [2,6,8], [9,4,1]]

for element in my_list:
	print(f"\t\tVamos a desglosar la lista {element}")
	for element_in_list in element:
		print(element_in_list)
	print("\n")

odd_list = [1,3,5,7,9]
cuadrado = [ i ** 2 for i in odd_list]			# for i in odd_list: i ** 2  (interesante...<3)

print(cuadrado)


