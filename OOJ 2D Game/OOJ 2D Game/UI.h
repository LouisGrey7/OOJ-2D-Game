#pragma once
#include "SFML/Graphics.hpp"

class UI
{
private:
	//Variables
	sf::RectangleShape* healthCounter;

	std::vector<sf::RectangleShape*> healthCounterVec;

	sf::Texture healthCounterTex;

	//Initialization



public:

	//Constructor/Destructors

	UI();
	~UI();

	//Functions


	//Update
	void Update(int _currentHealth, sf::Vector2f _camerapos);

	//Render
	void Render(sf::RenderTarget* _window);

	//Accessors
};

