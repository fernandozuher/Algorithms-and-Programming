# Author: Fernando Zuher
# Place: Brazil
# Date: 08 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 193
# 10-4. Guest Book: Write a while loop that prompts users for their name. When
# they enter their name, print a greeting to the screen and add a line recording
# their visit in a file called guest_book.txt. Make sure each entry appears on a
# new line in the file.

filename = 'guest_book.txt'
print("Type 'q' to stop the program.\n")

with open(filename, 'a') as file_object:
	while True:
		name = input('Tell me your name: ')
		if name != 'q':
			print(f"\tWelcome, {name}.\n")
			file_object.write(f"{name}\n")
		else:
			break