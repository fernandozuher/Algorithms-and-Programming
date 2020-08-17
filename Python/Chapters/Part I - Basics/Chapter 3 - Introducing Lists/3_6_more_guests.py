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

print(f"\n{guest_list[2]} can't make the dinner.")

guest_list[2] = 'Alessandro'
print(f"\n{guest_list[0]}, come to have dinner in my home. :-)")
print(f"{guest_list[1]}, come to have dinner in my home. :-)")
print(f"{guest_list[2]}, come to have dinner in my home. :-)")
print(f"{guest_list[3]}, come to have dinner in my home. :-)")

print('\nHello, everybody! I just found a new a bigger dinner table!')
guest_list.insert(0, 'Luisa')
guest_list.insert(2, 'Kavoos')
guest_list.append('Elizabeth')
print(f"\n{guest_list[0]}, come to have dinner in my home. :-)")
print(f"{guest_list[1]}, come to have dinner in my home. :-)")
print(f"{guest_list[2]}, come to have dinner in my home. :-)")
print(f"{guest_list[3]}, come to have dinner in my home. :-)")
print(f"{guest_list[4]}, come to have dinner in my home. :-)")
print(f"{guest_list[5]}, come to have dinner in my home. :-)")
print(f"{guest_list[6]}, come to have dinner in my home. :-)")