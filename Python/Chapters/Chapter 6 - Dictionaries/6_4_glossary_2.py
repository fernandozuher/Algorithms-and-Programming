# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-4. Glossary 2: Now that you know how to loop through a dictionary, clean
# up the code from Exercise 6-3 (page 99) by replacing your series of print()
# calls with a loop that runs through the dictionary’s keys and values. When
# you’re sure that your loop works, add five more Python terms to your glossary.
# When you run your program again, these new words and meanings should
# automatically be included in the output.

programming_words = {
	'print("string")': 'print some string to the monitor.',
	'input("ask")': 'take an input by the keyboard.',
	'.lstrip()': 'remove white space in the beginning of a string, if there is.',
	'.rstrip()': 'remove white space in the end of a string, if there is.',
	'.strip()': 'remove white space in the beginning and end of a string, if there is.',
	'.sort()': 'sort a list.',
	'sorted("list")': 'return the list put as argument in its sorted way',
	'min(list)': 'return the minimum element of a list.',
	'max(list)': 'return the maximum element of a list.',
	'sum(list)': 'return the sum of the numbers of a list.'
}

for key, value in programming_words.items():
	print(f"{key}: {value}")
