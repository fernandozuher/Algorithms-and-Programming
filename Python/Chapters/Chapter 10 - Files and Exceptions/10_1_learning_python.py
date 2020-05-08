# Author: Fernando Zuher
# Place: Brazil
# Date: 08 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 191
# 10-1. Learning Python: Open a blank file in your text editor and write a few
# lines summarizing what you’ve learned about Python so far. Start each line
# with the phrase In Python you can. . . . Save the file as learning_python.txt in
# the same directory as your exercises from this chapter. Write a program that
# reads the file and prints what you wrote three times. Print the contents once by
# reading in the entire file, once by looping over the file object, and once by stor-
# ing the lines in a list and then working with them outside the with block.

filename = 'learning_python.txt'
with open(filename) as file_object:
	print(file_object.read())

print()
with open(filename) as file_object:
	for line in file_object:
		print(line.rstrip())

print()
with open(filename) as file_object:
	lines = file_object.readlines()
for line in lines:
	print(line.rstrip())

