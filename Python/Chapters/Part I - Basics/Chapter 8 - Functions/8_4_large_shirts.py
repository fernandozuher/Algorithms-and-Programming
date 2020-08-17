# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-4. Large Shirts: Modify the make_shirt() function so that shirts are large
# by default with a message that reads I love Python. Make a large shirt and a
# medium shirt with the default message, and a shirt of any size with a different
# message.

def make_shirt(size='L', message='I love Python'):
	print("The size and message to be printed on the T-shirt are")
	print(f"\tsize: {size}.")
	print(f"\tmessage: '{message}'")

make_shirt()
make_shirt('M')
make_shirt('P', 'Hello, World!')