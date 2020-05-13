# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 202
# 10-9. Silent Cats and Dogs: Modify your except block in Exercise 10-8 to fail
# silently if either file is missing.

filename1 = 'cats.txt'
filename2 = 'dogs.txt'

try:
	with open(filename1) as f1:
		print('Cat names:')
		for name in f1:
			print(f"\t- {name.rstrip()}")

		print()

except FileNotFoundError:
	pass

try:
	with open(filename2) as f2:
		print('Dog names:')
		for name in f2:
			print(f"\t- {name.rstrip()}")

except FileNotFoundError:
	pass