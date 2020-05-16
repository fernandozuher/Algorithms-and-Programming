import unittest
from employee import Employee

class TestEmployee(unittest.TestCase):
	"""Test for the class var_Employee."""

	def setUp(self):
		"""
		Create a employee and a variable with a custom annual_salary for use in
		 all test methods.
		"""

		self.var_employee = Employee('First_Name', 'Last_Name', 200_000)
		self.raise_annual_salary = 50_000
		self.initial_annual_salary = self.var_employee.annual_salary

	def test_give_default_raise(self):
		"""Test a default raise in the annual salary."""		
		self.var_employee.give_raise()
		self.assertEqual(self.initial_annual_salary + 5000,
			self.var_employee.annual_salary)

	def test_give_custom_raise(self):
		"""Test a custom raise in the annual salary."""
		self.var_employee.give_raise(self.raise_annual_salary)
		self.assertEqual(self.initial_annual_salary + self.raise_annual_salary,
			self.var_employee.annual_salary)

if __name__ == '__main__':
	unittest.main()