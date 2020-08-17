# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 181
# 9-13. Dice: Make a class Die with one attribute called sides, which has a default
# value of 6. Write a method called roll_die() that prints a random number
# between 1 and the number of sides the die has. Make a 6-sided die and roll it
# 10 times.

# Make a 10-sided die and a 20-sided die. Roll each die 10 times.

from random import randint

class Die:
	"""For exercise 9-13."""

	def __init__(self, sides=6):
		"""Initialize attribute sides."""
		self.sides = sides

	def roll_die(self):
		"""
		Prints a random number between 1 and the
		number of sides the attribute die has.
		"""
		print(randint(1, self.sides), end=" ")


die6 = Die()
print('6-sided die rolled 10 times:', end=" ")
for value in range(10):
	die6.roll_die()

die10 = Die(10)
print('\n10-sided die rolled 10 times:', end=" ")
for value in range(10):
	die10.roll_die()

die20 = Die(20)
print('\n20-sided die rolled 10 times:', end=" ")
for value in range(10):
	die20.roll_die()

print()