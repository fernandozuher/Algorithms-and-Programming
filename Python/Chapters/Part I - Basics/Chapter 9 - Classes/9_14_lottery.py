# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 181
# 9-14. Lottery: Make a list or tuple containing a series of 10 numbers and
# five letters. Randomly select four numbers or letters from the list and print a
# message saying that any ticket matching these four numbers or letters wins a
# prize.

from random import randint, choice

ticket = []
for v in range(10):
	ticket.append(randint(1, 10))

ticket.append('a')
ticket.append('b')
ticket.append('c')
ticket.append('d')
ticket.append('e')

print('Any ticket matching these four numbers or letters: ', end="")
for v in range(4):
	print(choice(ticket), end="")

print('\n...wins a prize!')
