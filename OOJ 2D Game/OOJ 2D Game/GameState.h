#pragma once
#include "SFML/Graphics.hpp"
#include "Scene.h"

#include <iostream>


class GameState
{
private:


public:
	enum currentGameState
	{

		currentState_Menu,
		currentState_Rules,
		currentState_Playing,
		currentState_Win,
		currentState_Debug

	};

	//Variables

	sf::RectangleShape* background;
	int uiElementCount = 3;
	currentGameState m_currentState = currentState_Menu;
	float m_ButtonWidth = 260;
	float m_ButtonHeight = 80;
	std::vector<sf::RectangleShape*> m_UIElements;
	std::vector<sf::Text> m_UITextElements;
	sf::Texture m_buttonTex;
	sf::Text m_winText;
	sf::Text m_titleText;
	sf::Font* titleFont;
	sf::Font* buttonFont;

	//Constructor and Destructor
	GameState(sf::Vector2f _centerScreen);
	~GameState();

	//Functions
	void CreateMenu(sf::Vector2f _centerScreen);
	void DestroyMenu();

	//Update
	void Update(sf::RenderWindow* _window, sf::Vector2f _camerapos);
	void WinScreenUpdate(sf::RenderWindow* _window, sf::Vector2f _centerScreen);

	//Render
	void Render(sf::RenderWindow* _window);
	void WinScreenRender(sf::RenderWindow* _window);
};

