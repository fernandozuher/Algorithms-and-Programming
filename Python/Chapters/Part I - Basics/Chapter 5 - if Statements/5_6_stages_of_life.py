# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 5 - if Statements

# 5-6. Stages of Life: Write an if - elif - else chain that determines a person’s
# stage of life. Set a value for the variable age , and then:

# • If the person is less than 2 years old, print a message that the person is
# a baby.
# • If the person is at least 2 years old but less than 4, print a message that
# the person is a toddler.
# • If the person is at least 4 years old but less than 13, print a message that
# the person is a kid.
# • If the person is at least 13 years old but less than 20, print a message that
# the person is a teenager.
# • If the person is at least 20 years old but less than 65, print a message that
# the person is an adult.
# • If the person is age 65 or older, print a message that the person is an
# elder.

age = 32
if age < 2:
	print("Baby boy!")

elif age >= 2 and age < 4:
	print("Toddler boy!")

elif age >= 4 and age < 13:
	print("Kid!")

elif age >= 13 and age < 20:
	print("Teenager, bah...")

elif age >= 20 and age < 65:
	print("Adult.")

else:
	print("Elder.")