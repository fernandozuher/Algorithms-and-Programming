# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-2. Favorite Numbers: Use a dictionary to store people’s
# favorite numbers.
# Think of five names, and use them as keys in your dictionary.
# Think of a favorite number for each person, and store each as
# a value in your dictionary. Print each person’s name and their
# favorite number. For even more fun, poll a few friends and get
# some actual data for your program.

favorite_numbers = {
	'matheus': 7,
	'marcos': 3,
	'lucas': 5,
	'joão': 9,
	'paulo': 12
}

print(f"Matheus' favorite number is {favorite_numbers['matheus']}.")
print(f"Marcos' favorite number is {favorite_numbers['marcos']}.")
print(f"Lucas' favorite number is {favorite_numbers['lucas']}.")
print(f"João' favorite number is {favorite_numbers['joão']}.")
print(f"Paulo' favorite number is {favorite_numbers['paulo']}.")