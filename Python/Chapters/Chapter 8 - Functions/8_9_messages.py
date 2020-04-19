# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-9. Messages: Make a list containing a series of short text messages. Pass the
# list to a function called show_messages(), which prints each text message.

list = [
	'Lorem ipsum dolor sit amet,',
	'consectetur adipisicing elit, sed do eiusmod',
	'tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,',
	'quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
	'consequat.'
]

def show_messages(list):
	for message in list:
		print(message)

show_messages(list)