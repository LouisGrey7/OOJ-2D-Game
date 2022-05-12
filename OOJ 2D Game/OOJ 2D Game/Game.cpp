#include "Game.h"

//Static Functions


//Initializer Functions
void Game::InitWindow()
{

	std::ifstream ifs("Config/window.ini");


	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::InitStates()
{
	this->states.push(new GameState(this->window));
}

//Constructor/Destructors
Game::Game()
{
	this->InitWindow();
	this->InitStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

}

//Functions

void Game::EndApplication()
{
	std::cout << "Ending Application" << "\n";
}

void Game::UpdateDt()
{
	//updates the delta time variable
	this->dt = this->dtClock.restart().asSeconds();

}

void Game::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}

}

void Game::Update()
{
	this->UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{
		this->EndApplication();
		this->window->close();
	}
}

void Game::Render()
{
	this->window->clear();

	//render items
	if (!this->states.empty())
		this->states.top()->Render(this->window);

	this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}
