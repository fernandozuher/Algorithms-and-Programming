# Author: Fernando Zuher
# Place: Brazil
# Date: 18/04/2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 8 - Functions

# 8-8. User Albums: Start with your program from Exercise 8-7. Write a while
# loop that allows users to enter an album’s artist and title. Once you have that
# information, call make_album() with the user’s input and print the dictionary
# that’s created. Be sure to include a quit value in the while loop.

def make_album(artist, album_title):
	return {'artist': artist, 'album_title': album_title}

albums = []
while True:
	print("(enter 'q' at any time to quit)")
	artist_name = input("Inform artist name: ")
	if artist_name == 'q':
		break

	album_title = input("Inform the album title: ")
	if album_title == 'q':
		break

	albums.append({'artist_name': artist_name, 'album_title': album_title})
	
for album in albums:
	print(make_album(album['artist_name'], album['album_title']))

