class Employee:
	"""
	Class representing an employee with first and last name, and annual salary.
	"""

	def __init__(self, first_name, last_name, annual_salary):
		"""Initialize attributes first_name, last_name and annual_salary."""
		self.fist_name = first_name
		self.last_name = last_name
		self.annual_salary = annual_salary

	def give_raise(self, annual_raise=5000):
		"""Add 5000 by default or a different amount of money
		   in attribute annual_salary."""
		self.annual_salary += annual_raise