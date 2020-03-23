# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-9. Favorite Places: Make a dictionary called favorite_places. Think of three
# names to use as keys in the dictionary, and store one to three favorite places
# for each person. To make this exercise a bit more interesting, ask some friends
# to name a few of their favorite places. Loop through the dictionary, and print
# each person’s name and their favorite places.

favorite_places = {'fernando': ['italy', 'usa', 'france'], 'zuher': ['england'], 'cavalcante': ['spain', 'germany']}

for name, places in favorite_places.items():
	
	if len(places) > 1:
		print(f"\nThe favorite places of {name.title()} are:")
	
		for place in places:
			if place != 'usa':
				print("\t" + place.title())
			else:
				print("\t" + place.upper())
	else:
		print(f"\nThe favorite place of {name.title()} is:")
		if place != 'usa':
			print(f"\t{places[0].title()}")
		else:
			print(f"\t{places[0].upper()}")

