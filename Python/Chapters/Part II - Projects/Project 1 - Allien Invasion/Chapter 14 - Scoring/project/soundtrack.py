import pygame
import pygame.mixer
from pygame.mixer import Sound, music, Channel

from time import sleep
import random
import glob

class Soundtrack:

    def __init__(self):

        pygame.mixer.pre_init(44100, 16, 2, 4096)
        pygame.init()
        pygame.mixer.init(frequency=44100)

        self.menu = glob.glob("sounds/menu/*")
        self.playing = glob.glob("sounds/playing/*")
        self.shots = glob.glob("sounds/shots/*")
        self.exploded_alien = glob.glob("sounds/exploded_alien/*")
        self.lost_ship = glob.glob("sounds/lost_ship/*")
        self.new_level = glob.glob("sounds/new_level/*")
        self.new_high_score = glob.glob("sounds/new_high_score/*")
        self.game_over = glob.glob("sounds/game_over/*")
        
        self.sound_type = { 'menu': self.menu, 'playing': self.playing,
            'shots': self.shots, 'exploded_alien': self.exploded_alien,
            'lost_ship': self.lost_ship, 'new_level': self.new_level,
            'new_high_score': self.new_high_score, 'game_over': self.game_over
        }

        self._load_sounds()

    def _load_sounds(self):
        """Load sounds to be played."""

        self.sound_files = dict()
        # Get address files
        for key in self.sound_type.keys():
            limit = len(self.sound_type[key]) - 1
            index = random.randint(0, limit)
            self.sound_files[key] = self.sound_type[key][index]

        self.opened_sounds, self.channels = dict(), dict()
        i = 0
        # For shots, exploded_alien, lost_ship, new_level
        for key in list(self.sound_type.keys())[2:]:
            self.opened_sounds[key] = Sound(self.sound_files[key])
            self.channels[key] = pygame.mixer.Channel(i)
            i += 1

        music.load(self.sound_files['menu'])
        music.play(loops = -1)
        self.channels['shots'].set_volume(0.1)
        self.channels['exploded_alien'].set_volume(0.2)
        self.channels['lost_ship'].set_volume(1.0)
        self.channels['new_level'].set_volume(0.6)
        self.channels['game_over'].set_volume(1.0)

    def play_sound(self, type):
        """Play soundtrack."""
    
        if type == 'menu' or type == 'playing':
            music.load(self.sound_files[type])
            music.play(loops = -1)
            if type == 'playing':
                music.set_volume(0.2)
            else:
                music.set_volume(0.5)
        else:
            if type == 'game_over':
            	music.stop()
            	sleep(1.5)
            self.channels[type].play(self.opened_sounds[type])