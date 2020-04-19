# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-7. Album: Write a function called make_album() that builds a dictionary
# describing a music album. The function should take in an artist name and an
# album title, and it should return a dictionary containing these two pieces of
# information. Use the function to make three dictionaries representing different
# albums. Print each return value to show that the dictionaries are storing the
# album information correctly.
# Use None to add an optional parameter to make_album() that allows you to
# store the number of songs on an album. If the calling line includes a value for
# the number of songs, add that value to the album’s dictionary. Make at least
# one new function call that includes the number of songs on an album.

def make_album(artist, album_title, songs=None):
	album = {'artist': artist, 'album_title': album_title}
	if songs:
		album['songs'] = songs
	return album

print(make_album('Artist1', 'Album1'))
print(make_album('Artist2', 'Album2'))
print(make_album('Artist3', 'Album3'))
print(make_album('Artist3', 'Album4', 7))