class Settings:
	"""A class to store all settings for Alien Invasion."""
	def __init__(self):
		"""Initialize the game's settings."""
		# Screen settings
		self.screen_width = 1200
		self.screen_height = 800
		self.bg_color = (230, 230, 230)
		
		# Ship settings
		self.ship_speed = 1.5
		self.ship_limit = 3

		# Bullet settings
		self.bullet_speed = 3
		self.bullet_width = 15
		self.bullet_height = 3
		self.bullet_color = (60, 60, 60)
		self.bullets_allowed = 3

		# Rectangle settings
		self.rectangle_speed = 1.0
		# fleet_direction of 1 represents up; -1 represents down.
		self.rectangle_direction = 1
		self.rectangle_width = 100
		self.rectangle_height = 15
		self.rectangle_color = (255, 0, 0)
