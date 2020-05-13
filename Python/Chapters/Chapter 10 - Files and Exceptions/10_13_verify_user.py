# Author: Fernando Zuher
# Place: Brazil
# Date: 13 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 10 - Files and Exceptions

# Page 208
# 10-13. Verify User: The final listing for remember_me.py assumes either that the
# user has already entered their username or that the program is running for the
# first time. We should modify it in case the current user is not the person who
# last used the program.

# Before printing a welcome back message in greet_user(), ask the user if
# this is the correct username. If it’s not, call get_new_username() to get the correct
# username.

import json

def get_stored_username():
	"""Get stored username if available."""
	filename = 'username.json'
	try:
		with open(filename) as f:
			username = json.load(f)
	except FileNotFoundError:
		return None
	else:
		return username

def get_new_username():
	"""Prompt for a new username."""
	username = input("What is your name? ")
	filename = 'username.json'
	with open(filename, 'w') as f:
		json.dump(username, f)
	return username

def greet_user():
	"""Greet the user by name."""
	username = get_stored_username()

	if username:
		answer = input(f"Is the username '{username}' yours? Type 'y' (yes) or 'n' (no): ")
		if answer == 'y':
			print(f"Welcome back, {username}!")
		elif answer == 'n':
			username = None
		else:
			print(f"Your answer is invalid: {answer}. It is accepted just 'y' or 'n'.")
	
	if username == None:
		username = get_new_username()
		print(f"We'll remember you when you come back, {username}!")

greet_user()