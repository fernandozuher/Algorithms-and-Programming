# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 4 - Working with Lists

cubes = []
for cube in range(1, 11):
	cubes.append(cube**3)

for cube in cubes:
	print(cube)