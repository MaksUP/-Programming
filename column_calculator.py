import random

len_mas1 = int(input("Введіть довжину першого масива: "))
len_mas2 = int(input("Введіть довжину другого масива: "))
sign = input("Оберіть операцію (+, -): ")

mas1 = [random.randint(1, 9) for i in range(len_mas1)]
mas2 = [random.randint(1, 9) for i in range(len_mas2)]
mas3 = []

len1 = len(mas1)
len2 = len(mas2)
len3 = len(mas3)
temp = 0
num1 = 0
num2 = 0


def Addition(len1, len2, num1, num2, temp, mas1, mas2, mas3):
	while (len1-1 >= 0 or len2-1 >= 0 or temp):

		if len1-1 < 0:
			num1 = 0
		else: 
			num1 = mas1[len1-1] 

		if len2-1 < 0:
			num2 = 0
		else: 
			num2 = mas2[len2-1] 
	
		mas3.append(int((num1 + num2) + temp) % 10)
		temp = ((num1 + num2) + temp) // 10

		len1 -= 1
		len2 -= 1

	return mas3


def Subtraction(len1, len2, num1, num2, temp, mas1, mas2, mas3):
	done = False
	negative = False
	str_mas1 = ""
	str_mas2 = ""

	for el in mas1:
		str_mas1 += str(el)
	for el in mas2:
		str_mas2 += str(el)

	while (len1-1 >= 0 or len2-1 >= 0 or temp):

		if len1-1 < 0:
			num1 = 0
		else: num1 = mas1[len1-1] 

		if len2-1 < 0:
			num2 = 0
		else: num2 = mas2[len2-1] 
		
		if int(str_mas1) > int(str_mas2):

			if num1-num2 < 0:
				num1 += 10
				done = True
			else:
				done = False

			mas3.append(int((num1 - num2) - temp))

			if done: temp = 1
			else: temp = 0

		elif int(str_mas1) < int(str_mas2):

			if num2-num1 < 0:
				num2 += 10
				done = True
			else:
				done = False

			mas3.append(int((num2 - num1) - temp))

			if done: temp = 1
			else: temp = 0

			negative = True

		else:

			mas3.append(0)
			break

		len1 -= 1
		len2 -= 1

	if negative: 
		mas3[len3-1] = -mas3[len3-1]

	return mas3

print(mas1)
print(mas2)

if sign == "+": 
	Addition(len1, len2, num1, num2, temp, mas1, mas2, mas3)

elif sign == "-": 
	Subtraction(len1, len2, num1, num2, temp, mas1, mas2, mas3)

print(mas3[::-1])