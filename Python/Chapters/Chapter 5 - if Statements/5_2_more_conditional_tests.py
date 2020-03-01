# 5-2. More Conditional Tests: You don’t have to limit the number of tests you
# create to ten. If you want to try more comparisons, write more tests and add
# them to conditional_tests.py. Have at least one True and one False result for
# each of the following:

print("• Tests for equality and inequality with strings")
print("Is 'JavaScript' == 'JavaScript'?")
print('JavaScript' == 'JavaScript')

print("\nIs 'Javascript' == 'JavaScript'?")
print('Java' == 'JavaScript')

print("\n• Tests using the lower() method")
print("Is 'JavaScript' == 'javascript'?")
print('JavaScript'.lower() == 'javascript'.lower())

print("\nIs 'Javascripts' == 'JavaScript'?")
print('Javascripts'.lower() == 'JavaScript'.lower())

print("\n• Numerical tests involving equality and inequality, greater than and")
print("less than, greater than or equal to, and less than or equal to")
print("5 == 5?")
print(5 == 5)

print("\n5 != 5?")
print(5 != 5)

print("\n5 > 5")
print(5 > 5)

print("\n5 < 5")
print(5 < 5)

print("\n5 >= 5")
print(5 >= 5)

print("\n5 <= 5")
print(5 <= 5)

print("\n• Tests using the 'and' keyword and the 'or' keyword")
print("True and True?")
print(True and True)

print("\nTrue or True?")
print(True or True)

print("\nFalse or False?")
print(False or False)

print("\n• Test whether an item is in a list")
lista = ['Lorem', 'ipsum', 'dolor', 'sit', 'amet']
print(f"lista: {lista}")
print("\tdolor is in list?")
print(f"\t{'dolor' in lista}")

print("\n\tlorem is in list?")
print(f"\t{'lorem' in lista}")

print("\n• Test whether an item is not in a list")
print(f"lista: {lista}")
print("\tdolor is in list?")
print(f"\t{'dolor' in lista}")

print("\n\tlorem is in list?")
print(f"\t{'lorem' in lista}")