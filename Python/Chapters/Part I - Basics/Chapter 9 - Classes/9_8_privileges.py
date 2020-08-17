# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 173
# 9-8. Privileges: Write a separate Privileges class. The class should have one
# attribute, privileges, that stores a list of strings as described in Exercise 9-7.
# Move the show_privileges() method to this class. Make a Privileges instance
# as an attribute in the Admin class. Create a new instance of Admin and use your
# method to show its privileges.

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


class Admin(User):
	"""For exercise 9-7"""

	def __init__(self, first_name, last_name, gender, age, privileges):
		"""Initialize atributes of the class and of its super class."""
		super().__init__(first_name, last_name, gender, age)
		self.privileges = Privileges(privileges)


class Privileges():
	"""For exercise 9-8."""
	
	def __init__(self, privileges):
		"""Initialize attribute privileges."""
		self.privileges = privileges

	def show_privileges(self):
		""" Print the administrator’s set of privileges."""
		for key in self.privileges:
			print(f"- {key}")


privileges = ["can add post", "can delete post", "can ban user"]
admin = Admin('Thanos', 'god', 'M', 'unknown', privileges)

print('The administrator’s set of privileges are:')
admin.privileges.show_privileges()