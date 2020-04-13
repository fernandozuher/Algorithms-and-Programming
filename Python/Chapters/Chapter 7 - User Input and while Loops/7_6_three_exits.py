# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-6. Three Exits: Write different versions of either Exercise 7-4 or Exercise 7-5
# that do each of the following at least once:
# • Use a conditional test in the while statement to stop the loop.
# • Use an active variable to control how long the loop runs.
# • Use a break statement to exit the loop when the user enters a 'quit' value.

# • Use a conditional test in the while statement to stop the loop.
print("Tell me your age or type 'quit' to stop it.")
age = ""
while age != 'quit':
	
	age = input("\nAge: ")
	if age == 'quit':
		continue

	age = int(age)
	if age > 0 and age < 3:
		print("\tYour ticket is free.")
	elif age >=3 and age <= 12:
		print("\tYour ticket is $10.")
	elif age > 12:
		print("\tYour ticket is $15.")
	else:
		print(f"\tThis age ({age}) is not valid. Try again.")

print("---------------------")
# • Use an active variable to control how long the loop runs.
repeat = 0
while repeat < 3:
	repeat += 1

	age = int(input("\nTell me your age: "))

	if age > 0 and age < 3:
		print("\tYour ticket is free.")
	elif age >=3 and age <= 12:
		print("\tYour ticket is $10.")
	elif age > 12:
		print("\tYour ticket is $15.")
	else:
		print(f"\tThis age ({age}) is not valid. Try again.")

print("---------------------")
# • Use a break statement to exit the loop when the user enters a 'quit' value.
print("\nTell me your age or type 'quit' to stop it.")
age = ""
while True:
	
	age = input("\nAge: ")
	if age == 'quit':
		break

	age = int(age)
	if age > 0 and age < 3:
		print("\tYour ticket is free.")
	elif age >=3 and age <= 12:
		print("\tYour ticket is $10.")
	elif age > 12:
		print("\tYour ticket is $15.")
	else:
		print(f"\tThis age ({age}) is not valid. Try again.")


