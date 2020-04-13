# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-5. Movie Tickets: A movie theater charges different ticket prices depending on
# a person’s age. If a person is under the age of 3, the ticket is free; if they are
# between 3 and 12, the ticket is $10; and if they are over age 12, the ticket is
# $15. Write a loop in which you ask users their age, and then tell them the cost
# of their movie ticket.

while True:
	age = int(input("\nTell me your age: "))
	if age > 0 and age < 3:
		print("\tYour ticket is free.")
	elif age >=3 and age <= 12:
		print("\tYour ticket is $10.")
	elif age > 12:
		print("\tYour ticket is $15.")
	else:
		print(f"\tThis age ({age}) is not valid. Try again.")
