#pragma once
#include "SFML/Graphics.hpp"
#include "Collisions.h"

class Enemies
{
private:
	//Variables
	sf::RectangleShape* m_enemyShape;
	sf::Vector2f m_enemyPos;
	sf::Texture m_enemyTex;
	sf::Vector2f m_enemyMoveVec = sf::Vector2f(-1.0f, 0.0f);
	std::vector<Enemies> m_enemyVec;

public:
	//Variables
	float m_enemySpeed = 200.0f;
	float enemyYVelocity = 0.0f;
	bool colliding = false;

	//Initialization


	//Constructor/Destructors
	Enemies();

	~Enemies();
		
	//Functions

	void DestroyEnemy();

	//Update
	void Update(float _dt, float _movedirx, float _movediry, std::vector<sf::FloatRect> _Collisions, std::vector<sf::FloatRect> _patrolCollide);


	//Render
	void Render(sf::RenderTarget* _window);


	//Accessors
	sf::RectangleShape* EnemyGetShape();

};

