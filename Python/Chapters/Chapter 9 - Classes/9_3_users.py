# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 162
# 9-3. Users: Make a class called User. Create two attributes called first_name
# and last_name, and then create several other attributes that are typically stored
# in a user profile. Make a method called describe_user() that prints a summary
# of the user’s information. Make another method called greet_user() that prints
# a personalized greeting to the user.

# Create several instances representing different users, and call both methods
# for each user.

class User:
	"""For exercise 9-3"""

	def __init__(self, first_name, last_name, gender, age):
		"""Initialize first_name, last_name, gender and age attributes."""
		self.first_name = first_name
		self.last_name = last_name
		self.gender = gender
		self.age = age

	def describe_user(self):
		"""Print data about a user."""
		print(f"Full name = {self.first_name} {self.last_name}")
		print(f"Gender = {self.gender}")
		print(f"Age = {self.age}")

	def greet_user(self):
		"""Print a personalized greeting to a user."""
		print(f"Welcome, {self.first_name}!")


user1 = User('Petista', 'Safado', 'M', '18')
user1.describe_user()
user1.greet_user()

print()
user2 = User('Albert', 'Einstein', 'M', '50')
user2.describe_user()
user2.greet_user()

print()
user3 = User('Isaac', 'Newton', 'M', '43')
user3.describe_user()
user3.greet_user()

