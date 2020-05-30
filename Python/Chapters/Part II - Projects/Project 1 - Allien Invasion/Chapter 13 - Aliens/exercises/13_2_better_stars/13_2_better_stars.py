# Author: Fernando Zuher
# Place: Brazil
# Date: 29 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 13 - Aliens!

# 13-2. Better Stars: You can make a more realistic star pattern by
# introducing randomness when you place each star. Recall that you can get a
# random number like this:
#
# from random import randint
# random_number = randint(-10, 10)
#
# This code returns a random integer between −10 and 10. Using your code
# in Exercise 13-1, adjust each star’s position by a random amount.

import sys
import pygame
from random import randint

from settings import Settings
from star import Star

class StarGrid:
	"""Overall class to manage game assets and behavior."""

	def __init__(self):
		"""Initialize the game, and create game resources."""
		pygame.init()
		self.settings = Settings()
		
		self.screen = pygame.display.set_mode(
			(self.settings.screen_width, self.settings.screen_height))
		#self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
		self.settings.screen_width = self.screen.get_rect().width
		self.settings.screen_height = self.screen.get_rect().height
		pygame.display.set_caption("13.2. Better Stars")

		self.stars = pygame.sprite.Group()
		self._create_grid()

	def _check_keydown_events(self, event):
		"""Respond to keypresses."""
		# print(event.key)
		if event.key == pygame.K_q:
			sys.exit()

	def _check_events(self):
		"""Respond to keypresses and mouse events."""
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				self._check_keydown_events(event)

	def _create_grid(self):
		"""Create the grid of stars."""
		
		TOTAL_STARS = 100
		# Create the full grid of stars.
		for row_number in range(TOTAL_STARS):
			self._create_star()
	
	def _create_star(self):
		"""Create an star and place it in the row."""
		star = Star(self)
		star_width, star_height = star.rect.size
		
		random_number = randint(0, self.settings.screen_width - star_width)
		star.rect.x = random_number
		random_number = randint(0, self.settings.screen_height - star_height)
		star.rect.y = random_number

		self.stars.add(star)

	def _update_screen(self):
		"""Update images on the screen, and flip to the new screen."""
		self.screen.fill(self.settings.bg_color)
		self.stars.draw(self.screen)

		# Make the most recently drawn screen visible.
		pygame.display.flip()

	def run_game(self):
		"""Start the main loop for the game."""
		while True:
			self._check_events()
			self._update_screen()

if __name__ == '__main__':
	# Make a game instance, and run the game.
	ai = StarGrid()
	ai.run_game()