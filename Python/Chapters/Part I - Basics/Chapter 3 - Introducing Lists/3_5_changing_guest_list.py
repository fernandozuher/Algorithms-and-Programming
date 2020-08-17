# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 3 - Introducing Lists

guest_list = ['Stefano', 'Linda', 'Marco', 'Roxana']
print(f"{guest_list[0]}, come to have dinner in my home. :-)")
print(f"{guest_list[1]}, come to have dinner in my home. :-)")
print(f"{guest_list[2]}, come to have dinner in my home. :-)")
print(f"{guest_list[3]}, come to have dinner in my home. :-)")

print(f"{guest_list[2]} can't make the dinner.")

guest_list[2] = 'Alessandro'
print(f"{guest_list[0]}, come to have dinner in my home. :-)")
print(f"{guest_list[1]}, come to have dinner in my home. :-)")
print(f"{guest_list[2]}, come to have dinner in my home. :-)")
print(f"{guest_list[3]}, come to have dinner in my home. :-)")