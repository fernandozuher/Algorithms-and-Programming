class Settings:
	"""A class to store all settings for Alien Invasion."""
	def __init__(self):
		"""Initialize the game's settings."""
		# Screen settings
		self.screen_width = 1200
		self.screen_height = 800
		self.bg_color = (230, 230, 230)
		
		# Ship settings
		self.ship_limit = 3

		# Bullet settings
		self.bullet_width = 15
		self.bullet_height = 3
		self.bullet_color = (60, 60, 60)
		self.bullets_allowed = 3

		# Rectangle settings
		# fleet_direction of 1 represents up; -1 represents down.
		self.rectangle_width = 100
		self.rectangle_height = 15
		self.rectangle_color = (255, 0, 0)

		# How quickly the game speeds up
		self.speedup_scale = 1.1
		self.initialize_dynamic_settings(0)

	def initialize_dynamic_settings(self, level):
		"""Initialize settings that change throughout the game."""
		if level == 0:
			self.ship_speed = 3.0
			self.bullet_speed = 5
			self.rectangle_speed = 1
			self.bullet_width = 300
			self.bullet_height = 60
		elif level == 1:
			self.ship_speed = 2.0
			self.bullet_speed = 2
			self.rectangle_speed = 3
			self.bullet_width = 200
			self.bullet_height = 40
		elif level == 2:
			self.ship_speed = 1
			self.bullet_speed = 4
			self.rectangle_speed = 5
			self.bullet_width = 100
			self.bullet_height = 20
		
		self.rectangle_direction = 1

	def increase_speed(self):
		"""Increase speed settings."""
		self.ship_speed *= self.speedup_scale
		self.bullet_speed *= self.speedup_scale
		self.rectangle_speed *= self.speedup_scale