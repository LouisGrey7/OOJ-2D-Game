#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include <iostream>

#include "Collisions.h"

class Character
{
private:
	//Variables
	sf::RectangleShape* charShape;


	sf::Vector2f charSize = sf::Vector2f(80.0f,80.0f);
	sf::Vector2f charMoveVec = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f charPos = sf::Vector2f(0.0f, 0.0f);

	sf::Texture charTex;


	//Initialization
	void InitCharacter();


public:
	float charSpeed = 300;
	int characterHealth = 3;
	bool colliding = false;
	float charYVelocity = 0.0f;
	float jumpHeight = -10.0f;
	float currentJumpCount = 3;
	float maxJumpCount = 3;

	//Constructor/Destructors
	Character();
	virtual ~Character();

	//Functions
	void Move(float _dt, std::vector<sf::FloatRect> _Collisions);

	//Update
	void CharacterInputUpdate(float _dt, std::vector<sf::FloatRect> _Collisions);
	void Update(float _dt, std::vector<sf::FloatRect> _Collisions);

	//Render
	void Render(sf::RenderTarget* _window);
	
	//Accessors
	sf::RectangleShape* GetCharacterShape();
	sf::Vector2f GetCharacterPosition();
};
