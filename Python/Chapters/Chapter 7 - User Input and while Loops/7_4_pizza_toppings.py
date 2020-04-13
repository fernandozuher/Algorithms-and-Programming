# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-4. Pizza Toppings: Write a loop that prompts the user to enter a series of
# pizza toppings until they enter a 'quit' value. As they enter each topping,
# print a message saying you’ll add that topping to their pizza.

print("Tell me your toppings, then type 'quit' when you are done.")
topping = ""
number = 1
while True:
	topping = input(f"Topping {number}: ")
	if topping == "quit":
		break
	number += 1
	print(f"\tYou’ll add {topping} to the pizza.\n")

