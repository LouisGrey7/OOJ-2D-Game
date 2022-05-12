#ifndef GAME_H
#define GAME_H

#include "GameState.h"



class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;

	sf::Clock dtClock;
	float dt;


	std::stack<State*> states;

	//Initialization
	void InitWindow();
	void InitStates();


public:

	//Constructor/Destructors
	Game();
	virtual ~Game();

	//Functions
	void EndApplication();
	//Update
	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();

	//Render
	void Render();

	//Run
	void Run();
};


#endif