import pygame
from pygame.sprite import Sprite

class Rectangle(Sprite):
	"""A class to represent a single alien in the fleet."""
	
	def __init__(self, ai_game):
		"""Initialize the rectangle and set its starting position."""
		super().__init__()
		self.screen = ai_game.screen
		self.settings = ai_game.settings
		self.color = self.settings.rectangle_color

		# Create a rectangle at (0, 0) and then set correct position.
		self.rect = pygame.Rect(0, 0, self.settings.rectangle_width,
			self.settings.rectangle_height)
		self.rect.midright = ai_game.screen.get_rect().midright

		# Start each new alien near the top left of the screen.
		#self.rect.x = self.rect.width
		#self.rect.y = self.rect.height

		# Store the alien's exact horizontal position.
		self.x = float(self.rect.x)
		self.y = float(self.rect.y)

	def check_edges(self):
		"""Return True if rectangle is at edge of screen."""
		screen_rect = self.screen.get_rect()
		if self.rect.top <= 0 or self.rect.bottom >= screen_rect.height:
			return True

	def center_rectangle(self):
		"""Center the ship on the screen."""
		self.rect.midright = self.screen.get_rect().midright
		self.x = float(self.rect.x)
		self.y = float(self.rect.y)
		self.settings.rectangle_direction = 1

	def update(self):
		"""Move the rectangle up or down."""
		self.y += self.settings.rectangle_speed * self.settings.rectangle_direction
		self.rect.y = self.y

	def draw_rectangle(self):
		"""Draw the rectangle to the screen."""
		pygame.draw.rect(self.screen, self.color, self.rect)
