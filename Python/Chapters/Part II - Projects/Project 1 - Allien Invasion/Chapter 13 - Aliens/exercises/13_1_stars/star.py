import pygame
from pygame.sprite import Sprite

class Star(Sprite):
	"""A class to represent a single start in the fleet."""
	
	def __init__(self, ai_game):
		"""Initialize the start and set its starting position."""
		super().__init__()
		self.screen = ai_game.screen

		# Load the start image and set its rect attribute.
		self.image = pygame.image.load('images/star.bmp')
		self.rect = self.image.get_rect()

		# Start each new start near the top left of the screen.
		self.rect.x = self.rect.width
		self.rect.y = self.rect.height

		# Store the start's exact horizontal position.
		self.x = float(self.rect.x)