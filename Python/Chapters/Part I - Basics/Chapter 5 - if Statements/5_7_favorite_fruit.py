# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 5 - if Statements

# 5-7. Favorite Fruit: Make a list of your favorite fruits, and then write a series of
# independent if statements that check for certain fruits in your list.

# • Make a list of your three favorite fruits and call it favorite_fruits .
# • Write five if statements. Each should check whether a certain kind of fruit
# is in your list. If the fruit is in your list, the if block should print a statement,
# such as You really like bananas!

fruits = ['laranja', 'banana', 'maçã', 'melão', 'mamão']

if 'laranja' in fruits:
	print('laranja' in fruits)
if 'banana' in fruits:
	print('banana' in fruits)
if 'maçã' in fruits:
	print('maçã' in fruits)

favorite_fruits = ['laranja', 'banana', 'maçã']
if 'laranja' in favorite_fruits:
	print("You really like laranja!")

if 'banana' in favorite_fruits:
	print("You really like banana!")

if 'maçã' in favorite_fruits:
	print("You really like maçã!")

if 'melão' in favorite_fruits:
	print("You really like melão!")

if 'mamão' in favorite_fruits:
	print("You really like mamão!")


