# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# Page 155
# 8-16. Imports: Using a program you wrote that has one function in it, store that
# function in a separate file. Import the function into your main program file, and
# call the function using each of these approaches:

	# import module_name
	# from module_name import function_name
	# from module_name import function_name as fn
	# import module_name as mn
	# from module_name import *

import full_name
print(full_name.formatted_name('fernando', 'zuher'))

from full_name import formatted_name
print(formatted_name('fernando', 'zuher'))

from full_name import formatted_name as fn
print(fn('fernando', 'zuher'))

import full_name as mn
print(mn.formatted_name('fernando', 'zuher'))

from full_name import *
print(formatted_name('fernando', 'zuher'))