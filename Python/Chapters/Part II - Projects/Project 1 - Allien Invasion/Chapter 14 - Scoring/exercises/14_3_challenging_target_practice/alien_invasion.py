# Author: Fernando Zuher
# Place: Brazil
# Date: 11 June 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 14 - Scoring

# 14-3. Challenging Target Practice: Start with your work from Exercise 14-2
# (page 285). Make the target move faster as the game progresses, and restart
# the target at the original speed when the player clicks Play.

import sys
from time import sleep

import pygame

from settings import Settings
from game_stats import GameStats
from button import Button
from ship import Ship
from bullet import Bullet
from rectangle import Rectangle

class AlienInvasion:
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
		pygame.display.set_caption("14-3. Challenging Target Practice")

		# Create an instance to store game statistics.
		self.stats = GameStats(self)

		self.ship = Ship(self)
		self.bullets = pygame.sprite.Group()
		self.rectangles = pygame.sprite.Group()

		self._create_rectangle()

		# Make the Play button.
		self.play_button = Button(self, "Play")

	def _check_keydown_events(self, event):
		"""Respond to keypresses."""
		if event.key == pygame.K_UP:
			self.ship.moving_top = True
		elif event.key == pygame.K_DOWN:
			self.ship.moving_bottom = True
		elif event.key == pygame.K_SPACE:
			self._fire_bullet()
		elif event.key == pygame.K_q:
			sys.exit()
		
	def _check_keyup_events(self, event):
		"""Respond to key releases."""
		if event.key == pygame.K_UP:
			self.ship.moving_top = False
		elif event.key == pygame.K_DOWN:
			self.ship.moving_bottom = False

	def _fire_bullet(self):
		"""Create a new bullet and add it to the bullets group."""
		if len(self.bullets) < self.stats.bullets_left:
			new_bullet = Bullet(self)
			self.bullets.add(new_bullet)
		#elif not self.stats.game_active:
		#	self.stats.game_active = True

	def _check_events(self):
		"""Respond to keypresses and mouse events."""
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				self._check_keydown_events(event)
			elif event.type == pygame.KEYUP:
				self._check_keyup_events(event)
			elif event.type == pygame.MOUSEBUTTONDOWN:
				mouse_pos = pygame.mouse.get_pos()
				self._check_play_button(mouse_pos)

	def _check_play_button(self, mouse_pos):
		"""Start a new game when the player clicks Play."""
		button_clicked = self.play_button.rect.collidepoint(mouse_pos)
		if button_clicked and not self.stats.game_active:
			# Reset the game settings.
			self.settings.initialize_dynamic_settings()

			# Reset the game statistics.
			self.stats.reset_stats()
			self.stats.game_active = True

			# Get rid of any remaining aliens and bullets.
			#self.rectangles.empty()
			self.bullets.empty()

			# Center the ship.
			self.ship.center_ship()

			# Hide the mouse cursor.
			pygame.mouse.set_visible(False)

	def _update_bullets(self):
		"""Update position of bullets and get rid of old bullets."""
		# Update bullet positions.
		self.bullets.update()

		# Get rid of bullets that have disappeared.
		for bullet in self.bullets.copy():
			if bullet.rect.right >= self.settings.screen_width:
				self.bullets.remove(bullet)
				self.stats.bullets_left -= 1
		
		if self.stats.bullets_left == 0:
			self.stats.game_active = False
			self.bullets.empty()
			self.stats.reset_stats()
			self.rectangles.empty()
			self._create_rectangle()

			self.play_button.draw_button()
			pygame.mouse.set_visible(True)

		else:
			self._check_bullet_rectangle_collision()
	
	def _check_bullet_rectangle_collision(self):
		"""Respond to bullet-alien collisions."""
		# Remove any bullets and aliens that have collided.
		collision = pygame.sprite.groupcollide(
				self.bullets, self.rectangles, True, True)

		if not self.rectangles:
			self.bullets.empty()
			self.rectangles.empty()
			self.stats.reset_stats()
			self.ship.center_ship()

			self._create_rectangle()

			self.settings.increase_speed()

	def _update_rectangle(self):
		"""Check if the rectangle is at an edge, then update its position."""
		"""Respond appropriately if rectangle have reached an edge."""
		for rectangle in self.rectangles.sprites():
			if rectangle.check_edges():
				self._change_rectangle_direction()
			rectangle.update()
	
	def _create_rectangle(self):
		"""Create an alien and place it in the row."""
		rectangle = Rectangle(self)
		rectangle.center_rectangle()
		self.rectangles.add(rectangle)

	def check_edges(self):
		"""Return True if rectangle is at edge of screen."""
		for rectangle in self.rectangles.sprites():
			if rectangle.check_edges():
				self._change_rectangle_direction()
				break
	
	def _change_rectangle_direction(self):
		"""Drop the entire fleet and change the fleet's direction."""
		self.settings.rectangle_direction *= -1

	def _update_screen(self):
		"""Update images on the screen, and flip to the new screen."""
		self.screen.fill(self.settings.bg_color)
		self.ship.blitme()
		for bullet in self.bullets.sprites():
			bullet.draw_bullet()

		for rect in self.rectangles.sprites():
			rect.draw_rectangle()

		# Draw the play button if the game is inactive.
		if not self.stats.game_active:
			self.play_button.draw_button()

		# Make the most recently drawn screen visible.
		pygame.display.flip()

	def run_game(self):
		"""Start the main loop for the game."""
		while True:
			self._check_events()

			if self.stats.game_active:
				self.ship.update()
				self._update_bullets()
				self._update_rectangle()
			
			self._update_screen()

if __name__ == '__main__':
	# Make a game instance, and run the game.
	ai = AlienInvasion()
	ai.run_game()