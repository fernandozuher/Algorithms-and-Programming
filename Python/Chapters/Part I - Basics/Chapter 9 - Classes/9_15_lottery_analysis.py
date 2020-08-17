# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 181
# 9-15. Lottery Analysis: You can use a loop to see how hard it might be to win
# the kind of lottery you just modeled. Make a list or tuple called my_ticket.
# Write a loop that keeps pulling numbers until your ticket wins. Print a message
# reporting how many times the loop had to run to give you a winning ticket.

from random import randint, choice

ticket = []
for v in range(10):
	ticket.append(v)

ticket.append('a')
ticket.append('b')
ticket.append('c')
ticket.append('d')
ticket.append('e')

my_ticket = [1, 2, 3, 4]
winning_ticket = []
times = 0

while my_ticket != winning_ticket:
	winning_ticket = []
	for v in range(4):
		winning_ticket.append(choice(ticket))
	
	times += 1

print(f"The loop had to run {times} times to give me a winning ticket: {my_ticket}.")
