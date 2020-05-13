# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 208
# 10-12. Favorite Number Remembered: Combine the two programs from
# Exercise 10-11 into one file. If the number is already stored, report the favorite
# number to the user. If not, prompt for the user’s favorite number and store it in a
# file. Run the program twice to see that it works.

import json

filename = 'favorite_number.txt'
try:
	with open(filename) as f:
		favorite_number = json.load(f)

except FileNotFoundError:

	try:
		number = int(input('Tell me your favorite number: '))
	except ValueError:
		print("You didn't input a number in a decimal format.")
	else:
		with open('favorite_number.txt', "w") as f:
			json.dump(number, f)

else:
	print(f"I know your favorite number! It's {favorite_number}.")

