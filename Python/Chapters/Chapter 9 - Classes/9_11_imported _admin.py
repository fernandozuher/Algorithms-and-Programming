# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 180
# 9-11. Imported Admin: Start with your work from Exercise 9-8 (page 173).
# Store the classes User, Privileges, and Admin in one module. Create a sepa-
# rate file, make an Admin instance, and call show_privileges() to show that
# everything is working correctly.

from user import Admin

privileges = ["can add post", "can delete post", "can ban user"]
admin = Admin('Thanos', 'god', 'M', 'unknown', privileges)

print('The administrator’s set of privileges are:')
admin.privileges.show_privileges()