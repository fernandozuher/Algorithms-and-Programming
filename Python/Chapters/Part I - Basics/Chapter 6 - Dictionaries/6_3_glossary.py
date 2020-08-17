# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-3. Glossary: A Python dictionary can be used to model an actual dictionary.
# However, to avoid confusion, let’s call it a glossary.

	# • Think of five programming words you’ve learned about in the previous
	# chapters. Use these words as the keys in your glossary, and store their
	# meanings as values.
	
	# • Print each word and its meaning as neatly formatted output. You might
	# print the word followed by a colon and then its meaning, or print the word
	# on one line and then print its meaning indented on a second line. Use the
	# newline character (\n) to insert a blank line between each word-meaning
	# pair in your output.

programming_words = {
	'print': 'print some string to the monitor.',
	'input': 'take an input by the keyboard.',
	'lstrip': 'remove white space in the beginning of a string, if there is.',
	'rstrip': 'remove white space in the end of a string, if there is.',
	'strip': 'remove white space in the beginning and end of a string, if there is.'
}

print(f"print: {programming_words['print']}")
print(f"input: {programming_words['input']}")
print(f"lstrip: {programming_words['lstrip']}")
print(f"rstrip: {programming_words['rstrip']}")
print(f"strip: {programming_words['strip']}")