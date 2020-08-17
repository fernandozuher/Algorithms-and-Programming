# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 5 - if Statements

# 5-11. Ordinal Numbers: Ordinal numbers indicate their position in a list, such
# as 1st or 2nd. Most ordinal numbers end in th, except 1, 2, and 3.

# • Store the numbers 1 through 9 in a list.
# • Loop through the list.
# • Use an if - elif - else chain inside the loop to print the proper ordinal end-
# ing for each number. Your output should read "1st 2nd 3rd 4th 5th 6th
# 7th 8th 9th" , and each result should be on a separate line.

numbers = list(range(1, 10))
for number in numbers:
	
	if number == 1:
		print(f"{number}st")

	elif number == 2:
		print(f"{number}nd")

	elif number == 3:
		print(f"{number}rd")

	else:
		print(f"{number}th")