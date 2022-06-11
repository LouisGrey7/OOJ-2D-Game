#include "Enemies.h"

Enemies::Enemies()
{
	m_enemyShape = new sf::RectangleShape(sf::Vector2f(80.0f, 80.0f));
	m_enemyShape->setFillColor(sf::Color::White);
	m_enemyShape->setPosition(1000.0f,1000.0f);
	m_enemyShape->setOrigin(sf::Vector2f(40.0f, 40.0f));

	if (!m_enemyTex.loadFromFile("Sprites/Enemy.png"))
	{

	}

	m_enemyShape->setTexture(&m_enemyTex);
}

Enemies::~Enemies()
{
}

void Enemies::DestroyEnemy()
{
}

void Enemies::Update(float _dt, float _movedirx, float _movediry, std::vector<sf::FloatRect> _Collisions, std::vector<sf::FloatRect> _patrolCollide)
{
	m_enemyPos = m_enemyShape->getPosition();

	//m_enemyMoveVec = (m_enemyPos - sf::Vector2f(_movedirx, _movediry));
	float m_enemyDistance = sqrt(pow((_movedirx - m_enemyPos.x), 2) + pow((_movediry - m_enemyPos.y), 2));


	

	if(m_enemyMoveVec.y < 0)
	{
		m_enemyShape->move(sf::Vector2f(0, 1 * m_enemySpeed * _dt));
	}
	if (m_enemyMoveVec.y > 0)
	{
		m_enemyShape->move(sf::Vector2f(0, -1 * m_enemySpeed * _dt));
	}

	for (int i = 0; i < _Collisions.size(); i++)
	{
		if (m_enemyShape->getGlobalBounds().intersects(_Collisions[i]))
		{
			colliding = true;
			enemyYVelocity = 0.0f;
			
			Collisions::ResolveYCollision(m_enemyShape, _Collisions[i], true);
		}
		else
		{
			colliding = false;
		}
		
	}

	if (m_enemyMoveVec.x < 0)
	{
		m_enemyShape->move(sf::Vector2f(-1 * m_enemySpeed * _dt, 0));
		m_enemyShape->setScale(1, 1);
	}
	if (m_enemyMoveVec.x > 0)
	{
		m_enemyShape->move(sf::Vector2f(1 * m_enemySpeed * _dt, 0));
		m_enemyShape->setScale(-1, 1);
	}
	
	for (int i = 0; i < _Collisions.size(); i++)
	{
		if (m_enemyShape->getGlobalBounds().intersects(_Collisions[i]))
		{
			Collisions::ResolveXCollision(EnemyGetShape(), _Collisions[i], true);
		}
	}
	for (int i = 0; i < _patrolCollide.size(); i++)
	{
		if (m_enemyShape->getGlobalBounds().intersects(_patrolCollide[i]))
		{
			Collisions::ResolveXCollision(EnemyGetShape(), _patrolCollide[i], true);

			m_enemyMoveVec.x = m_enemyMoveVec.x * -1;
		}
	}
}

void Enemies::Render(sf::RenderTarget* _window)
{
	_window->draw(*m_enemyShape);
}

sf::RectangleShape* Enemies::EnemyGetShape()
{
	return m_enemyShape;
}
