#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(sf::Color::White);
	this->movementspeed = 100.0f;
}

Entity::~Entity()
{
}

void Entity::Move(const float& _dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * this->movementspeed * _dt, dir_y * this->movementspeed * _dt);
}

void Entity::Update(const float& _dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Move(_dt, -1.0f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Move(_dt, 1.0f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->Move(_dt, 0.0f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->Move(_dt, 0.0f, 1.f);
	}
}

void Entity::Render(sf::RenderTarget* _target)
{
	_target->draw(this->shape);
}
