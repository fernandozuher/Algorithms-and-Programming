# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 180
# 9-10. Imported Restaurant: Using your latest Restaurant class, store it in a mod-
# ule. Make a separate file that imports Restaurant. Make a Restaurant instance,
# and call one of Restaurant’s methods to show that the import statement is work-
# ing properly.

from restaurant import Restaurant

rest = Restaurant('Rio Samba', 'Brazilian')
rest.describe_restaurant()