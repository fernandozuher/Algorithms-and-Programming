# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 5 - if Statements

# 5-4. Alien Colors #2: Choose a color for an alien as you did in Exercise 5-3, and
# write an if - else chain.

# • If the alien’s color is green, print a statement that the player just earned
# 5 points for shooting the alien.
# • If the alien’s color isn’t green, print a statement that the player just earned
# 10 points.
# • Write one version of this program that runs the if block and another that
# runs the else block.

alien_color = 'yellow'
if alien_color == 'green':
	print("You just earned 5 points!")
else:
	print("You just earned 10 points!")