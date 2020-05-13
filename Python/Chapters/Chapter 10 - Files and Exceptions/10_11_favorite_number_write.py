# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 208
# 10-11. Favorite Number: Write a program that prompts for the user’s favorite
# number. Use json.dump() to store this number in a file. Write a separate pro-
# gram that reads in this value and prints the message, “I know your favorite
# number! It’s _____.”

# The separe program is called 10_11_favorite_number_read.py

import json

try:
	number = int(input('Tell me your favorite number: '))

except ValueError:
	print("You didn't input a number in a decimal format.")

else:
	with open('favorite_number.txt', "w") as f:
		json.dump(number, f)
