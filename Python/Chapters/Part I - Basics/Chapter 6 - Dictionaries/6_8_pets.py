# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-8. Pets: Make several dictionaries, where each dictionary represents a
# different pet. In each dictionary, include the kind of animal and the owner’s
# name. Store these dictionaries in a list called pets. Next, loop through your
# list and as you do, print everything you know about each pet.

pet1 = {'type': 'dog', 'owner': 'pedro'}
pet2 = {'type': 'cat', 'owner': 'maria'}
pet3 = {'type': 'rabbit', 'owner': 'paulo'}
pet4 = {'type': 'fish', 'owner': 'josé'}

pets = [pet1, pet2, pet3, pet4]

for pet in pets:
	print(f"{pet['owner'].title()} has a {pet['type']} as a pet.")