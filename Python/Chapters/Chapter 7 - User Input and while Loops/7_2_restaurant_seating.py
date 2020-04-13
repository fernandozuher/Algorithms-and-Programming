# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-2. Restaurant Seating: Write a program that asks the user how many people
# are in their dinner group. If the answer is more than eight, print a message say-
# ing they’ll have to wait for a table. Otherwise, report that their table is ready.

people = int(input("How many people are in your dinner group? "))
if people > 8:
	print("You'll have to wait for for a table.")
else:
	print("A table is ready for all of you.")