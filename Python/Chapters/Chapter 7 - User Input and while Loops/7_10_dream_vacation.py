# Author: Fernando Zuher
# Place: Brazil
# Date: 12/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 7 - User Input and while Loops

# 7-10. Dream Vacation: Write a program that polls users about their dream vaca-
# tion. Write a prompt similar to If you could visit one place in the world, where
# would you go? Include a block of code that prints the results of the poll.

places = []
print("Type 'quit' to finish the pool")
while True:
	place = input("If you could visit one place in the world, where would you go? ")
	if place == 'quit':
		break

	places.append(place)

print("Most dreamed places where to take vacation: ")
for place in places:
	print(f"\t{place}")
