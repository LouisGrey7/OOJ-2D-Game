#include "UI.h"

UI::UI()
{
	healthCounter = new sf::RectangleShape(sf::Vector2f(40,40));
	healthCounter->setFillColor(sf::Color::White);
	if (!healthCounterTex.loadFromFile("Sprites/HealthCounter.png"))
	{

	}
	
	healthCounter->setTexture(&healthCounterTex);



}

UI::~UI()
{
}

void UI::Update(int _currentHealth, sf::Vector2f _camerapos)
{
	for (int i = 0; i < _currentHealth; i++)
	{
		healthCounterVec.push_back(healthCounter);
		healthCounterVec[i]->setPosition(_camerapos - sf::Vector2f(800,500) + sf::Vector2f(20.0f * i, 0));
	}


}

void UI::Render(sf::RenderTarget* _window)
{
	_window->draw(*healthCounter);
}
