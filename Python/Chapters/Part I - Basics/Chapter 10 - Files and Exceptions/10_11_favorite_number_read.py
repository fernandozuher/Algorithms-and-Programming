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

# The original program is called 10_11_favorite_number_write.py

import json

filename = 'favorite_number.txt'
try:
	with open(filename) as f:
		favorite_number = json.load(f)

except FileNotFoundError:
	print(f"The file '{filename}' doesn't exist.")

else:
	print(f"I know your favorite number! It's {favorite_number}.")