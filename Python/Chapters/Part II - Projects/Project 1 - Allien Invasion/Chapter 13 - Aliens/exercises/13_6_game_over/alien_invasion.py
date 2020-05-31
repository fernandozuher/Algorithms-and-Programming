# Author: Fernando Zuher
# Place: Brazil
# Date: 31 May 2020
# Book: Python Crash Course, 2nd Edition. Author: ERIC MATTHES.
# About: Exercise, Chapter 13 - Aliens!

# 13-6. Game Over: In Sideways Shooter, keep track of the number of times the
# ship is hit and the number of times an alien is hit by the ship. Decide on
# an appropriate condition for ending the game, and stop the game when this
# situation occurs.

import sys
from time import sleep

import pygame

from settings import Settings
from game_stats import GameStats
from ship import Ship
from bullet import Bullet
from alien import Alien

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
		pygame.display.set_caption("Alien Invasion")

		# Create an instance to store game statistics.
		self.stats = GameStats(self)

		self.ship = Ship(self)
		self.bullets = pygame.sprite.Group()
		self.aliens = pygame.sprite.Group()

		self._create_fleet()										

	def _check_keydown_events(self, event):
		"""Respond to keypresses."""
		#print(event.key)
		if event.key == pygame.K_RIGHT:
			self.ship.moving_right = True
		elif event.key == pygame.K_LEFT:
			self.ship.moving_left = True
		elif event.key == pygame.K_UP:
			self.ship.moving_top = True
		elif event.key == pygame.K_DOWN:
			self.ship.moving_bottom = True
		elif event.key == pygame.K_SPACE:
			self._fire_bullet()
		elif event.key == pygame.K_q:
			sys.exit()
		
	def _check_keyup_events(self, event):
		"""Respond to key releases."""
		if event.key == pygame.K_RIGHT:
			self.ship.moving_right = False
		elif event.key == pygame.K_LEFT:
			self.ship.moving_left = False
		elif event.key == pygame.K_UP:
			self.ship.moving_top = False
		elif event.key == pygame.K_DOWN:
			self.ship.moving_bottom = False

	def _fire_bullet(self):
		"""Create a new bullet and add it to the bullets group."""
		if len(self.bullets) < self.settings.bullets_allowed:
			new_bullet = Bullet(self)
			self.bullets.add(new_bullet)

	def _check_events(self):
		"""Respond to keypresses and mouse events."""
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				sys.exit()
			elif event.type == pygame.KEYDOWN:
				self._check_keydown_events(event)
			elif event.type == pygame.KEYUP:
				self._check_keyup_events(event)

	def _update_bullets(self):
		"""Update position of bullets and get rid of old bullets."""
		# Update bullet positions.
		self.bullets.update()

		# Get rid of bullets that have disappeared.
		for bullet in self.bullets.copy():
			if bullet.rect.right >= self.settings.screen_width:
				self.bullets.remove(bullet)
		
		self._check_bullet_alien_collisions()
	
	def _check_bullet_alien_collisions(self):
		"""Respond to bullet-alien collisions."""
		# Remove any bullets and aliens that have collided.
		collisions = pygame.sprite.groupcollide(
				self.bullets, self.aliens, True, True)

		if collisions:
			self.stats.hit_aliens_left = len(self.aliens.sprites())
			if not self.stats.hit_aliens_left:
				self.stats.game_active = False
		
		# Destroy existing bullets and create new fleet.
		if not self.aliens:
			self.bullets.empty()
			if self.stats.game_active:
				self._create_fleet()
	
	def _update_aliens(self):
		"""
		Check if the fleet is at an edge,
		then update the positions of all aliens in the fleet.
		"""
		self._check_fleet_edges()
		self.aliens.update()

		# Look for alien-ship collisions.
		if pygame.sprite.spritecollideany(self.ship, self.aliens):
			self._ship_hit()

		# Look for aliens hitting the left of the screen.
		self._check_aliens_left()

	def _ship_hit(self):
		"""Respond to the ship being hit by an alien."""
		# Decrement ships_left.
		self.stats.ships_left -= 1
		if self.stats.ships_left > 0:
			# Get rid of any remaining aliens and bullets.
			self.aliens.empty()
			self.bullets.empty()
			
			# Create a new fleet and center the ship.
			self._create_fleet()
			self.ship.center_ship()
				
			# Pause.
			sleep(0.5)
		else:
			self.stats.game_active = False

	def _create_fleet(self):
		"""Create the fleet of aliens."""
		# Create an alien and find the number of aliens in a row.
		# Spacing between each alien is equal to one alien width.
		alien = Alien(self)
		alien_width, alien_height = alien.rect.size
		ship_height = self.ship.rect.height

		available_space_y = self.settings.screen_height - 2 * alien_height
		number_rows = available_space_y // (2 * alien_width)
		
		available_space_x = (self.settings.screen_width - (alien_width)
							- ship_height)
		number_aliens_y = available_space_x // (2 * alien_width)

		self.stats.hit_aliens_left = number_rows * number_aliens_y

		# Create the full fleet of aliens.
		for row_number in range(number_rows):
			for alien_number in range(number_aliens_y):
				self._create_alien(alien_number, row_number)
	
	def _create_alien(self, alien_number, row_number):
		"""Create an alien and place it in the row."""
		alien = Alien(self)
		alien_width, alien_height = alien.rect.size

		alien.x = 3 * alien_width + 2 * alien_width * alien_number
		alien.rect.x = alien.x
		
		alien.y = alien.rect.height + 2 * alien.rect.height * row_number
		alien.rect.y = alien.y
		self.aliens.add(alien)

	def _check_fleet_edges(self):
		"""Respond appropriately if any aliens have reached an edge."""
		for alien in self.aliens.sprites():
			if alien.check_edges():
				self._change_fleet_direction()
				break

	def _check_aliens_left(self):
		"""Check if any aliens have reached the bottom of the screen."""
		screen_rect = self.screen.get_rect()
		for alien in self.aliens.sprites():
			if alien.rect.left <= 0:
				# Treat this the same as if the ship got hit.
				self._ship_hit()
				break
	
	def _change_fleet_direction(self):
		"""Drop the entire fleet and change the fleet's direction."""
		for alien in self.aliens.sprites():
			alien.rect.x -= self.settings.fleet_drop_speed
		self.settings.fleet_direction *= -1

	def _update_screen(self):
		"""Update images on the screen, and flip to the new screen."""
		self.screen.fill(self.settings.bg_color)
		self.ship.blitme()
		for bullet in self.bullets.sprites():
			bullet.draw_bullet()
		self.aliens.draw(self.screen)

		# Make the most recently drawn screen visible.
		pygame.display.flip()

	def run_game(self):
		"""Start the main loop for the game."""
		while True:
			self._check_events()

			if self.stats.game_active:
				self.ship.update()
				self._update_bullets()
				self._update_aliens()
			
			self._update_screen()

if __name__ == '__main__':
	# Make a game instance, and run the game.
	ai = AlienInvasion()
	ai.run_game()