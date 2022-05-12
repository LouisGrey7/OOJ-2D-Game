#include "State.h"


//Constuctor Destructor
State::State(sf::RenderWindow* _window)
{
	this->window = _window;
	this->quit = false;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	// TODO: insert return statement here
	return this->quit;
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{

		this->quit = true;
	}
}
