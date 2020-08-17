# Author: Fernando Zuher
# Place: Brazil
# Date: February 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 3 - Introducing Lists

languages = ['English', 'Español', 'Italiano', "Français", "اَلْعَرَبِيَّةُ"]

print(languages)

languages.append('עִבְרִית')
print(languages)

languages.insert(0, 'Portuguese')
print(languages)

del languages[0]
print(languages)

print(f"Remove {languages.pop()} language")
print(f"Remove {languages.pop(2)} language")
languages.remove('English')
print(languages)

languages = ['English', 'Español', 'Italiano', "Français", "اَلْعَرَبِيَّةُ"]
languages.insert(0, 'Português')
languages.append('עִבְרִית')
print(languages)

print(f"\nTemporarily sorted list: {sorted(languages)}")
print(f"Original list: {languages}")

print(f"\nTemporarily sorted reverse list: {sorted(languages, reverse=True)}")
print(f"Original list: {languages}")

languages.reverse()
print(f"\nReverse list: {languages}")

languages.sort()
print(f"\nSorted list: {languages}")

languages.sort(reverse=True)
print(f"\nSorted reverse list: {languages}")

print(f"\nList size: {len(languages)}.")