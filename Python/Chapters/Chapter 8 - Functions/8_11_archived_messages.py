# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-11. Archived Messages: Start with your work from Exercise 8-10. Call the
# function send_messages() with a copy of the list of messages. After calling the
# function, print both of your lists to show that the original list has retained its
# messages.

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

send_messages(list[:])
print("")

print(list)
print("")

print(sent_messages)
