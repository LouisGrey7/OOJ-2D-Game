#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState :
	public State
{
private:
	Entity player;

public:
	GameState(sf::RenderWindow* _window);
	virtual ~GameState();


	//Function
	void EndState();

	void UpdateKeybinds(const float& _dt);
	void Update(const float& _dt);
	void Render(sf::RenderTarget* _target = nullptr);

};

#endif