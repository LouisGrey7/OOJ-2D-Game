#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>

#include "Collisions.h"

enum CharMovement
{
	MOVING_LEFT,
	MOVING_RIGHT,
	IDLE,
};
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
	bool colliding = false;
	float charYVelocity = 0.0f;
	float charXVelocity = 0.0f;
	float jumpHeight = -12.0f;
	float dashDistance = 10.0;
	float currentJumpCount = 2;
	float currentDashCount = 1;
	float maxJumpCount = 2;
	float maxDashCount = 1;
	CharMovement currentCharMovement;
	sf::IntRect animationRect;

	sf::Clock animationClock;

	//Constructor/Destructors
	Character();
	virtual ~Character();

	//Functions
	void Move(float _dt, std::vector<sf::FloatRect> _Collisions);
	void AnimateCharacter();
	

	//Update
	void CharacterInputUpdate(float _dt, std::vector<sf::FloatRect> _Collisions);
	void Update(float _dt, std::vector<sf::FloatRect> _Collisions);

	//Render
	void Render(sf::RenderTarget* _window);
	
	//Accessors
	sf::RectangleShape* GetCharacterShape();
	sf::Vector2f GetCharacterPosition();
};

