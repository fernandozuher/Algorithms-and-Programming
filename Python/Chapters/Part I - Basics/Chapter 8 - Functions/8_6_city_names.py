# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-6. City Names: Write a function called city_country() that takes in the name
# of a city and its country. The function should return a string formatted like this:
# 		"Santiago, Chile"
# Call your function with at least three city-country pairs, and print the
# values that are returned.

def city_country(city, country):
	return city.title() + ', ' + country.title()

print(city_country('São Paulo', 'Brasil'))
print(city_country('Gênova', 'Itália'))
print(city_country('Paris', 'França'))