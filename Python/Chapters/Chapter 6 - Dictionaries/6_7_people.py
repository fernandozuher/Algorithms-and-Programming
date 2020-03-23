# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-7. People: Start with the program you wrote for Exercise 6-1 (page 99).
# Make two new dictionaries representing different people, and store all three
# dictionaries in a list called people. Loop through your list of people. As you
# loop through the list, print everything you know about each person.

person1 = {'first_name': 'james', 'last_name': 'bond', 'age': 40, 'city': 'london'}
person2 = {'first_name': 'donald', 'last_name': 'knuth', 'age': 82, 'city': 'milwaukee'}
person3 = {'first_name': 'bill', 'last_name': 'gates', 'age': 64, 'city': 'seattle'}

people = [person1, person2, person3]

for person in people:
	full_name = f"{person['first_name'].title()} {person['last_name'].title()}"
	print(f"{full_name}, {person['age']} years old, lives in {person['city'].title()}")
