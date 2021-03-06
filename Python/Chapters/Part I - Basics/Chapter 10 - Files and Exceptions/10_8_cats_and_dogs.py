# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 202
# 10-8. Cats and Dogs: Make two files, cats.txt and dogs.txt. Store at least three
# names of cats in the first file and three names of dogs in the second file. Write
# a program that tries to read these files and print the contents of the file to the
# screen. Wrap your code in a try-except block to catch the FileNotFound error,
# and print a friendly message if a file is missing. Move one of the files to a dif-
# ferent location on your system, and make sure the code in the except block
# executes properly.

filename1 = 'cats.txt'
filename2 = 'dogs.txt'

try:
	with open(filename1) as f1:
		print('Cat names:')
		for name in f1:
			print(f"\t- {name.rstrip()}")
		
		print()

except FileNotFoundError:
	print(f"The file '{filename1}' was not found.")

try:
	with open(filename2) as f2:
		print('Dog names:')
		for name in f2:
			print(f"\t- {name.rstrip()}")

except FileNotFoundError:
	print(f"Error: The file '{filename2}' was not found.")