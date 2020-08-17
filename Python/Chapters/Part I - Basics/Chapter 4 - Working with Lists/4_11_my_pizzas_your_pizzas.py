# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 4 - Working with Lists

pizzas = ['frango com catupiry', 'calabresa', 'quatro queijos']
friend_pizzas = pizzas[:]

pizzas.append('chocolate')
friend_pizzas.append('vegetariana')

print("My favorite pizzas are:")
for pizza in pizzas:
    print(pizza)

print("\nMy friend's favorite pizzas are:")
for pizza in friend_pizzas:
    print(pizza)