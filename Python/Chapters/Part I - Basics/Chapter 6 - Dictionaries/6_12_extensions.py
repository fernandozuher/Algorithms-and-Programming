# Author: Fernando Zuher
# Place: Brazil
# Date: 22/03/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 6 - Dictionaries

# 6-12. Extensions: We’re now working with examples that are complex enough
# that they can be extended in any number of ways. Use one of the example pro-
# grams from this chapter, and extend it by adding new keys and values, chang-
# ing the context of the program or improving the formatting of the output.

# Store information about pizzas being ordered.
pizzas = { 
	'donald':
		{'crust': 'thick',
		'toppings': ['mushrooms', 'extra cheese'],
		'price': '20'
		},

	'bill':
		{'crust': 'thin',
		'toppings': ['bacon', 'pepperoni'],
		'price': '25'
		},

	'fernando':
		{'crust': 'normal',
		'toppings': ['catupiry (Brazilian cream cheese)', 'chicken'],
		'price': '30'
		}
}

# Summarize the orders.
for client, type in pizzas.items():

	print(f"{client.title()}, you ordered a {type['crust']}-crust pizza " 
		"with the following toppings:")
	
	for topping in type['toppings']:
		print("\t- " + topping)

	print(f"\nIt costs ${type['price']},00.\n")
