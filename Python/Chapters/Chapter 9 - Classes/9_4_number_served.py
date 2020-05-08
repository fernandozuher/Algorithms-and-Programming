# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 167
# 9-4. Number Served: Start with your program from Exercise 9-1 (page 162).
# Add an attribute called number_served with a default value of 0. Create an
# instance called restaurant from this class. Print the number of customers the
# restaurant has served, and then change this value and print it again.

# Add a method called set_number_served() that lets you set the number
# of customers that have been served. Call this method with a new number and
# print the value again.

# Add a method called increment_number_served() that lets you increment
# the number of customers who’ve been served. Call this method with any num-
# ber you like that could represent how many customers were served in, say, a
# day of business.

class Restaurant:
	"""For exercise 9-4."""

	def __init__(self, restaurant_name, cuisine_type):
		"""Initialize restaurant_name and cuisine_type attributes."""
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type
		self.number_served = 0

	def describe_restaurant(self):
		"""Print the restaurant's name and its cuisine type."""
		print(f"Restaurant: {self.restaurant_name}.")
		print(f"Cuisine type: {self.cuisine_type}.")

	def open_restaurant(self):
		"""Print the restaurant is open."""
		print(f"The restaurant {self.restaurant_name} is open!")

	def set_number_served(self, number_served):
		"""Set the number of customers that have been served."""
		self.number_served = number_served

	def increment_number_served(self, number_served):
		"""Increment the number of customers who’ve been served."""
		self.number_served += number_served


restaurant = Restaurant('Eataly', 'Italian')
print(restaurant.number_served)

restaurant.number_served = 15
print(restaurant.number_served)

restaurant.set_number_served(19)
print(restaurant.number_served)

restaurant.increment_number_served(7)
print(restaurant.number_served)
