# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-12. Sandwiches: Write a function that accepts a list of items a person wants
# on a sandwich. The function should have one parameter that collects as many
# items as the function call provides, and it should print a summary of the sand-
# wich that’s being ordered. Call the function three times, using a different num-
# ber of arguments each time.

def items_sandwiches(*list):
	print("It has been ordered a sandwich with the following ingredients:")
	for item in list:
		print(f"\t- {item}")

items_sandwiches('cheese')
items_sandwiches('lettuce', 'chicken')
items_sandwiches('catupiry', 'bacon', 'mostard')