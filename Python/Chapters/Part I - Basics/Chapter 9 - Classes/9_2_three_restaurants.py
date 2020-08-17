# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 162
# 9-2. Three Restaurants: Start with your class from Exercise 9-1. Create three
# different instances from the class, and call describe_restaurant() for each
# instance.

class Restaurant:
	"""For exercise 9-2."""

	def __init__(self, restaurant_name, cuisine_type):
		"""Initialize restaurant_name and cuisine_type attributes."""
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type

	def describe_restaurant(self):
		"""Print the restaurant's name and its cuisine type."""
		print(f"Restaurant: {self.restaurant_name}.")
		print(f"Cuisine type: {self.cuisine_type}.\n")

	def open_restaurant(self):
		"""Print the restaurant is open."""
		print(f"The restaurant {self.restaurant_name} is open!")

restaurant1 = Restaurant('Eataly', 'Italian')
restaurant2 = Restaurant('Marte', 'Marciana')
restaurant3 = Restaurant('Mercúrio', 'Mercuriana')

restaurant1.describe_restaurant()
restaurant2.describe_restaurant()
restaurant3.describe_restaurant()