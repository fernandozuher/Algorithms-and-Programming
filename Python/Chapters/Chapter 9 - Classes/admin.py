"""A set of classes that can be used to represent a user who has admin level."""

from simple_user import User

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