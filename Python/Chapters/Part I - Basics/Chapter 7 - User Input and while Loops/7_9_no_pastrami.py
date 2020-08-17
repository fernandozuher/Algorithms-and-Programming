# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-9. No Pastrami: Using the list sandwich_orders from Exercise 7-8, make sure
# the sandwich 'pastrami' appears in the list at least three times. Add code
# near the beginning of your program to print a message saying the deli has
# run out of pastrami, and then use a while loop to remove all occurrences of
# 'pastrami' from sandwich_orders . Make sure no pastrami sandwiches end up
# in finished_sandwiches.

sandwich_orders = ['pastrami', 'misto quente', 'pastrami', 'hamburguer', 'big mac', 'pastrami']
finished_sandwiches = []

print("The deli has run out of pastrami.")
while "pastrami" in sandwich_orders:
	sandwich_orders.remove('pastrami')

for sandwich in sandwich_orders:
	print(f"I made your {sandwich} sandwich.")
	finished_sandwiches.append(sandwich);

print("The sandwiches made were:")
for sandwich in finished_sandwiches:
	print(f"\t {sandwich}")



