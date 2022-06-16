#include "AudioManager.h"

AudioManager::AudioManager()
{
	sf::SoundBuffer sfxJumpB;
	sf::SoundBuffer sfxDashB;
	sf::SoundBuffer sfxDeathB;
	sf::SoundBuffer sfxWinB;

	if (!sfxJumpB.loadFromFile("Audio/Jump.wav"))
	{

	}
	if (!sfxDashB.loadFromFile("Audio/Dash.wav"))
	{

	}
	if (!sfxDeathB.loadFromFile("Audio/Death.wav"))
	{

	}
	if (!sfxWinB.loadFromFile("Audio/Win.wav"))
	{

	}
	sfxBufferVec.push_back(sfxJumpB);
	sfxBufferVec.push_back(sfxDashB);
	sfxBufferVec.push_back(sfxDeathB);
	sfxBufferVec.push_back(sfxWinB);


	sf::Music* track01 = new sf::Music();
	sf::Music* track02 = new sf::Music();

	if (!track01->openFromFile("Audio/Birds.wav"))
	{

	}
	if (!track02->openFromFile("Audio/BGM.wav"))
	{

	}
	bgmVec.push_back(track01);
	bgmVec.push_back(track02);
}

AudioManager::~AudioManager()
{
}
