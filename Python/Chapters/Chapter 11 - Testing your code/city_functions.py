def get_formatted_place(city, country, population=''):
	"""Generate a neatly formatted place with city and country."""
	
	if population:
		return f"{city.title()}, {country.title()} - population {population}"
	else:
		return f"{city}, {country}".title()