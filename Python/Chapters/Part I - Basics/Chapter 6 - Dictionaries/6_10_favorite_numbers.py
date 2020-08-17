# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-10. Favorite Numbers: Modify your program from Exercise 6-2 (page 99)
# so each person can have more than one favorite number. Then print each per-
# son’s name along with their favorite numbers.

favorite_numbers = {
	'matheus': [7, 4, 1],
	'marcos': [3, 19, 9],
	'lucas': [5],
	'joão': [9, 10, 15],
	'paulo': [12]
}

for name, numbers in favorite_numbers.items():
	if len(numbers) > 1:
		print(f"{name.title()}' favorite number are: ", end = "")
		for number in numbers:
			print(f"{number}, ", end = "")

	else:
		print(f"{name.title()}' favorite number is: {numbers[0]}.", end="")

	print("")
