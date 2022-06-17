#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include <iostream>
#include <ctime>

#include "Character.h"
#include "Camera.h"
#include "Scene.h"
#include "PhysicsSystem.h"
#include "Enemies.h"
#include "UI.h"
#include "GameState.h"
#include "AudioManager.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock dtClock;
	float dt = 0.0f;
	bool gravityEnabled = true;
	int currentLevel = 1;
	bool debugIsOpen = false;
	
	

	GameState* newGameState;

	Character newCharacter;

	std::vector<Enemies*> enemies;

	AudioManager* newAudioManager = new AudioManager();

	Camera newCamera;
	
	Scene* newScene;

	PhysicsSystem newPhysicsSystem;

	//Initialization
	void InitWindow();


public:
	//Constructor/Destructors
	Game();
	virtual ~Game();

	//Functions
	void SpawnEnemies();
	void UnspawnEnemies();
	void SpawnChar();
	void KillTile();
	void WinTile();
	

	//Update
	void UpdateDt();
	void Update();

	//Render
	void Render();

	//Run
	void Run();

	//Accessors
	
};

