# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 173
# 9-6. Ice Cream Stand: An ice cream stand is a specific kind of restaurant. Write
# a class called IceCreamStand that inherits from the Restaurant class you wrote
# in Exercise 9-1 (page 162) or Exercise 9-4 (page 167). Either version of
# the class will work; just pick the one you like better. Add an attribute called
# flavors that stores a list of ice cream flavors. Write a method that displays
# these flavors. Create an instance of IceCreamStand, and call this method.

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


class IceCreamStand(Restaurant):
	"""For exercise 9-6. It inherits from class Restaurant."""

	def __init__(self, restaurant_name, cuisine_type, flavors):
		"""Initialize atributes of the class and of its super class."""
		super().__init__(restaurant_name, cuisine_type)
		self.flavors = flavors

	def show_flavors(self):
		"""Print the flavors of the Ice Cream Stand."""
		print('Flavors:')
		for key in self.flavors:
			print(f"- {key}")


flavors = ['cioccolato', 'fondente', 'nocciola', 'limone', 'fragola']
ice_cream_restaurant = IceCreamStand('Bacio di Latte', 'Ice Cream', flavors)
ice_cream_restaurant.show_flavors()