import unittest
from city_functions import get_formatted_place

class TestCities(unittest.TestCase):
	"""Tests for 'city_functions.py'."""

	def test_city_country(self):
		""""Do places like 'Santiago, Chile' work?"""
		self.assertEqual(get_formatted_place('santiago', 'chile'),
												'Santiago, Chile')

	def test_city_country_population(self):
		"""Do places with population like
			'Santiago, Chile - population 5_000_000' work?"""
		self.assertEqual(get_formatted_place('santiago', 'chile', 5_000_000),
							'Santiago, Chile - population 5000000')

if __name__ == '__main__':
	unittest.main()