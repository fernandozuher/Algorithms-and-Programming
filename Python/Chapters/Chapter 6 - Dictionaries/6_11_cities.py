# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-11. Cities: Make a dictionary called cities. Use the names of three cities as
# keys in your dictionary. Create a dictionary of information about each city and
# include the country that the city is in, its approximate population, and one fact
# about that city. The keys for each city’s dictionary should be something like
# country, population, and fact. Print the name of each city and all of the
# information you have stored about it.

cities = {
	'são paulo':
		{'country': 'Brazil',
		'population': '12,18 mi',
		'fact': 'The biggest city in South America.'},
	'genova': 
		{'country': 'Italy',
		'population': '583.601',
		'fact': 'Cristóvão Colombo was born here.'},
	'paris':
		{'country': 'France',
		'population': '2,148 mi',
		'fact': 'It is spoken French there ¯\_(ツ)_/¯.'}
}

for city, information in cities.items():

	print(f"{city.title()}:")
	
	for key, value in information.items():
		print(f"\t{key.title()}: {value}")
	print("")