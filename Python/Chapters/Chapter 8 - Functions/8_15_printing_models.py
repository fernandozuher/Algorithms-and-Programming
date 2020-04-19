# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# Page 155
# 8-15. Printing Models: Put the functions for the example printing_models.py in a
# separate file called printing_functions.py. Write an import statement at the top
# of printing_models.py, and modify the file to use the imported functions.

import printing_functions

unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
completed_models = []

printing_functions.print_models(unprinted_designs, completed_models)
printing_functions.show_completed_models(completed_models)
