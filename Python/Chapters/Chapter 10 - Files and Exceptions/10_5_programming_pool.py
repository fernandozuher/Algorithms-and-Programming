# Author: Fernando Zuher
# Place: Brazil
# Date: 08 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 193
# 10-5. Programming Poll: Write a while loop that asks people why they like
# programming. Each time someone enters a reason, add their reason to a file
# that stores all the responses.

filename = 'responses.txt'
print("Type 'q' to stop the program.")

number = 1
with open(filename, 'w') as file_object:
	while True:
		answer = input(f"\nWhy do you like programming, person {number}: ")
		number +=1
		if answer != 'q':
			file_object.write(f"{answer}\n")
		else:
			break