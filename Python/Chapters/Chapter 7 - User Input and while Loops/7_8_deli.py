# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-8. Deli: Make a list called sandwich_orders and fill it with the names of vari-
# ous sandwiches. Then make an empty list called finished_sandwiches. Loop
# through the list of sandwich orders and print a message for each order, such
# as I made your tuna sandwich. As each sandwich is made, move it to the list
# of finished sandwiches. After all the sandwiches have been made, print a
# message listing each sandwich that was made.

sandwich_orders = ['misto quente', 'hamburguer', 'big mac']
finished_sandwiches = []

for sandwich in sandwich_orders:
	print(f"I made your {sandwich} sandwich.")
	finished_sandwiches.append(sandwich);

print("The sandwiches made were:")
for sandwich in finished_sandwiches:
	print(f"\t {sandwich}")

