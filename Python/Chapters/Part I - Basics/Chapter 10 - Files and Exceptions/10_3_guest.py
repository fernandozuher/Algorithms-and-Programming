# Author: Fernando Zuher
# Place: Brazil
# Date: 08 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 193
# 10-3. Guest: Write a program that prompts the user for their name. When they
# respond, write their name to a file called guest.txt.

filename = 'guest.txt'
print("Type 'q' to stop the program.\n")

with open(filename, 'w') as file_object:
	while True:
		name = input('Tell me your name: ')
		if name != 'q':
			file_object.write(f"{name}\n")
		else:
			break