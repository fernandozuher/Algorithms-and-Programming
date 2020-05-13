# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 201
# 10-6. Addition: One common problem when prompting for numerical input
# occurs when people provide text instead of numbers. When you try to convert
# the input to an int, you’ll get a ValueError. Write a program that prompts for
# two numbers. Add them together and print the result. Catch the ValueError if
# either input value is not a number, and print a friendly error message. Test your
# program by entering two numbers and then by entering some text instead of a
# number.

try:
	number1 = int(input('Input the first number: '))
	number2 = int(input('Input the second number: '))

except ValueError:
	print("You didn't type a number at all. Input it to be computed.")

else:
	print(f"{number1} + {number2} = {number1 + number2}")

