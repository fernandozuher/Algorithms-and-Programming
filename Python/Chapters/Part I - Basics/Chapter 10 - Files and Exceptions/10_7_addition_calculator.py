# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 202
# 10-7. Addition Calculator: Wrap your code from Exercise 10-6 in a while loop
# so the user can continue entering numbers even if they make a mistake and
# enter text instead of a number.

print('Type q to exit the program.')
while True:
	try:
		input1 = input('\nInput the first number: ')
		number1 = int(input1)

		input2 = input('Input the second number: ')
		number2 = int(input2)

	except ValueError:
		if input1 != 'q' and input2 != 'q':
			print("You didn't type a number at all. Input it to be computed.")
		else:
			break
	else:
		print(f"{number1} + {number2} = {number1 + number2}")

