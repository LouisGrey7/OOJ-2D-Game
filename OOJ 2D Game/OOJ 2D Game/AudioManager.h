#pragma once
#include <SFML/Audio.hpp>


class AudioManager
{
public:
	//Variables
	std::vector<sf::SoundBuffer> sfxBufferVec;
	std::vector<sf::Music*> bgmVec;

	sf::Sound effectPlayer;


	//Constructor
	AudioManager();
	~AudioManager();



};

