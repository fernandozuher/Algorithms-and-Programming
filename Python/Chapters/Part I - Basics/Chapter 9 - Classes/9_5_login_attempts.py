# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 167
# 9-5. Login Attempts: Add an attribute called login_attempts to your User
# class from Exercise 9-3 (page 162). Write a method called increment_login
# _attempts() that increments the value of login_attempts by 1. Write another
# method called reset_login_attempts() that resets the value of login_attempts
# to 0.

# Make an instance of the User class and call increment_login_attempts()
# several times. Print the value of login_attempts to make sure it was incremented
# properly, and then call reset_login_attempts(). Print login_attempts again to
# make sure it was reset to 0.

class User:
	"""For exercise 9-3"""

	def __init__(self, first_name, last_name, gender, age):
		"""Initialize first_name, last_name, gender and age attributes."""
		self.first_name = first_name
		self.last_name = last_name
		self.gender = gender
		self.age = age
		self.login_attempts = 0

	def describe_user(self):
		"""Print data about a user."""
		print(f"Full name = {self.first_name} {self.last_name}")
		print(f"Gender = {self.gender}")
		print(f"Age = {self.age}")

	def greet_user(self):
		"""Print a personalized greeting to a user."""
		print(f"Welcome, {self.first_name}!")

	def increment_login_attempts(self):
		"""Increment the value of login_attempts by 1."""
		self.login_attempts += 1

	def reset_login_attempts(self):
		"""Reset the value of login_attempts to 0."""
		self.login_attempts = 0


user = User('Isaac', 'Newton', 'M', '27')
user.increment_login_attempts()
user.increment_login_attempts()
user.increment_login_attempts()
print(user.login_attempts)

user.reset_login_attempts()
print(user.login_attempts)