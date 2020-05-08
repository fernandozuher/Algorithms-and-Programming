# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 162
# 9-1. Restaurant: Make a class called Restaurant. The __init__() method for
# Restaurant should store two attributes: a restaurant_name and a cuisine_type.
# Make a method called describe_restaurant() that prints these two pieces of
# information, and a method called open_restaurant() that prints a message
# indicating that the restaurant is open.

# Make an instance called restaurant from your class. Print the two attri-
# butes individually, and then call both methods.

class Restaurant:
	"""For exercise 9-1."""

	def __init__(self, restaurant_name, cuisine_type):
		"""Initialize restaurant_name and cuisine_type attributes."""
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type

	def describe_restaurant(self):
		"""Print the restaurant's name and its cuisine type."""
		print(f"Restaurant: {self.restaurant_name}.")
		print(f"Cuisine type: {self.cuisine_type}.")

	def open_restaurant(self):
		"""Print the restaurant is open."""
		print(f"The restaurant {self.restaurant_name} is open!")

restaurant = Restaurant('Eataly', 'Italian')

print(restaurant.restaurant_name)
print(restaurant.cuisine_type)

restaurant.describe_restaurant()
restaurant.open_restaurant()