"""A class that can be used to represent a restaurant"""

class Restaurant:
	"""For exercise 9-10"""

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