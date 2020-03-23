favorite_languages = {
	'jen': 'python',
	'sarah': 'c',
	'edward': 'ruby',
	'phil': 'python',
}

language = favorite_languages['sarah'].title()
print(f"Sarah's favorite language is {language}.")

print('-------------------')
for name, language in favorite_languages.items():
	print(f"{name.title()}'s favorite language is {language.title()}.")

print('-------------------')
for name in favorite_languages.keys():
	print(name.title())

print('-------------------')
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
	print(name.title())

	if name in friends:
		language = favorite_languages[name].title()
		print(f"\t{name.title()}, I see you love {language}!")

print('-------------------')
if 'erin' not in favorite_languages.keys():
	print("Erin, please take our poll!")

print('-------------------')
for name in sorted(favorite_languages.keys()):
	print(f"{name.title()}, thank you for taking the poll.")

print('-------------------')
print("The following languages have been mentioned:")
for language in favorite_languages.values():
	print(language.title())

print('-------------------')
print("The following languages have been mentioned:")
for language in set(favorite_languages.values()):
	print(language.title())

print('-------------------')
favorite_languages = {
	'jen': ['python', 'ruby'],
	'sarah': ['c'],
	'edward': ['ruby', 'go'],
	'phil': ['python', 'haskell'],
}

for name, languages in favorite_languages.items():
	print(f"\n{name.title()}'s favorite languages are:")

	for language in languages:
		print(f"\t{language.title()}")