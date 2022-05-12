#include "GameState.h"

GameState::GameState(sf::RenderWindow* _window)
	: State(_window)
{

}

GameState::~GameState()
{
}


void GameState::EndState()
{
	std::cout << " ending game state" << "\n";
}

void GameState::UpdateKeybinds(const float& _dt)
{
	this->CheckForQuit();
}

void GameState::Update(const float& _dt)
{
	this->UpdateKeybinds(_dt);
	this->player.Update(_dt);

}

void GameState::Render(sf::RenderTarget* _target)
{
	if (_target)
	{

	}
	else
	{
		this->player.Render(this->window);
	}
}
