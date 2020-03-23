# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-5. Rivers: Make a dictionary containing three major rivers and the country
# each river runs through. One key-value pair might be 'nile': 'egypt' .
# • Use a loop to print a sentence about each river, such as The Nile runs
# through Egypt.
# • Use a loop to print the name of each river included in the dictionary.
# • Use a loop to print the name of each country included in the dictionary.

rivers = {
	'amazonas': 'brazil',
	'nilo': 'egypt',
	'mississipi': 'usa'
}

for river, country in rivers.items():
	if country != 'usa':
		print(f"The {river.title()} runs through {country.title()}.")
	else:
		print(f"The {river.title()} runs through {country.upper()}.")

print('-------------------')
for river in rivers.keys():
	print(river.title())

print('-------------------')
for country in rivers.values():
	if country != 'usa':
		print(country.title())
	else:
		print(country.upper())