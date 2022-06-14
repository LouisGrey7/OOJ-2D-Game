#pragma once
#include "SFML/Graphics.hpp"

class Camera
{
public:

	//Variables
	sf::View* playerCamera;

	//Constructor and Destructor
	Camera();
	~Camera();

	//Update
	
	void Update(sf::RenderTarget* _window, sf::Vector2f _center);

	//Functions
	void SetView(sf::RenderTarget* _window, sf::Vector2f _center);
};

