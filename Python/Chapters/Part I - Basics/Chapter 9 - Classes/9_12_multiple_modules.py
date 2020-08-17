# Author: Fernando Zuher
# Place: Brazil
# Date: 07 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 9 - Classes

# Page 180
# 9-12. Multiple Modules: Store the User class in one module, and store the
# Privileges and Admin classes in a separate module. In a separate file, create
# an Admin instance and call show_privileges() to show that everything is still
# working correctly.

from admin import Admin

privileges = ["can add post", "can delete post", "can ban user"]
admin = Admin('Thanos', 'god', 'M', 'unknown', privileges)

print('The administrator’s set of privileges are:')
admin.privileges.show_privileges()