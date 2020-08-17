# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-3. T-Shirt: Write a function called make_shirt() that accepts a size and the
# text of a message that should be printed on the shirt. The function should print
# a sentence summarizing the size of the shirt and the message printed on it.
# Call the function once using positional arguments to make a shirt. Call the
# function a second time using keyword arguments.

def make_shirt(size, message):
	print("The size and message to be printed on the T-shirt are")
	print(f"\tsize: {size}.")
	print(f"\tmessage: '{message}'")

make_shirt('M', 'Hello, World!')
make_shirt(size='M', message='Hello, World!')