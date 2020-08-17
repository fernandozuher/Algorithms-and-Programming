# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-10. Sending Messages: Start with a copy of your program from Exercise 8-9.
# Write a function called send_messages() that prints each text message and
# moves each message to a new list called sent_messages as it’s printed. After
# calling the function, print both of your lists to make sure the messages were
# moved correctly.

list = [
	'Lorem ipsum dolor sit amet,',
	'consectetur adipisicing elit, sed do eiusmod',
	'tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,',
	'quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo',
	'consequat.'
]

sent_messages = []
def send_messages(list):
	while list:
		message = list.pop(0)
		print(message)
		sent_messages.append(message)

send_messages(list)
print("")

print(list)
print("")

print(sent_messages)
