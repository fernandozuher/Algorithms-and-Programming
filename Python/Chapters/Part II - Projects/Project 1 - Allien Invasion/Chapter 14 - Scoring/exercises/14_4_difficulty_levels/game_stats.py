class GameStats:
	"""Track statistics for Alien Invasion."""

	def __init__(self, ai_game):
		"""Initialize statistics."""
		self.settings = ai_game.settings
		self.bullets_left = 0
		self.reset_stats()

		# Start game in an inactive state.
		self.game_active = False

	def reset_stats(self):
		"""Initialize statistics that can change during the game."""
		self.bullets_left = self.settings.bullets_allowed