# Author: Fernando Zuher
# Place: Brazil
# Date: 30 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 13 - Aliens!

# 13-4. Steady Rain: Modify your code in Exercise 13-3 so when a row of rain-
# drops disappears off the bottom of the screen, a new row appears at the top of
# the screen and begins to fall.

import sys
import pygame	
from settings import Settings
from raindrop import RainDrop

class Rain:
	"""Overall class to manage game assets and behavior."""

	def __init__(self):
		"""Initialize the game, and create game resources."""
		pygame.init()
		self.settings = Settings()
		
		#self.screen = pygame.display.set_mode(
		#	(self.settings.screen_width, self.settings.screen_height))
		self.screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
		self.settings.screen_width = self.screen.get_rect().width
		self.settings.screen_height = self.screen.get_rect().height
		pygame.display.set_caption("Rain Drop")

		self.raindrops = pygame.sprite.Group()
		self._create_rain()										

	def _check_keydown_events(self, event):
		"""Respond to keypresses."""
		#print(event.key)
		if event.key == pygame.K_q:
			sys.exit()

	def _check_events(self):
		"""Respond to keypresses and mouse events."""
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				self._check_keydown_events(event)

	def _create_rain(self):
		"""Create the rain of raindrops."""
		# Create an raindrop and find the number of raindrops in a row.
		# Spacing between each raindrop is equal to one raindrop width.
		raindrop = RainDrop(self)
		raindrop_width, raindrop_height = raindrop.rect.size
		available_space_x = self.settings.screen_width - (2 * raindrop_width)
		number_raindrops_x = available_space_x // raindrop_width
		
		# Determine the number of rows of raindrops that fit on the screen.
		available_space_y = self.settings.screen_height - 3 * raindrop_height
		number_rows = available_space_y // (2 * raindrop_height)
		
		# Create the full rain of raindrops.
		for row_number in range(number_rows):
			for raindrop_number in range(number_raindrops_x):
				self._create_raindrop(raindrop_number, row_number)
	
	def _create_raindrop(self, raindrop_number, row_number):
		"""Create an raindrop and place it in the row."""
		raindrop = RainDrop(self)
		raindrop_width, raindrop_height = raindrop.rect.size
		raindrop.x = raindrop_width + raindrop_width * raindrop_number
		raindrop.rect.x = raindrop.x
		
		raindrop.y = raindrop.rect.height + 2 * raindrop.rect.height * row_number
		raindrop.rect.y = raindrop.y

		self.raindrops.add(raindrop)

	def _update_screen(self):
		"""Update images on the screen, and flip to the new screen."""
		self.screen.fill(self.settings.bg_color)
		self.raindrops.draw(self.screen)

		# Make the most recently drawn screen visible.
		pygame.display.flip()

	def run_game(self):
		"""Start the main loop for the game."""
		while True:
			self._check_events()
			self.raindrops.update()
			self._update_screen()

if __name__ == '__main__':
	# Make a game instance, and run the game.
	ai = Rain()
	ai.run_game()