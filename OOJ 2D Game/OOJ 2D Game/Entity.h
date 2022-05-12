#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementspeed;

public:
	Entity();
	virtual ~Entity();

	//Function
	virtual void Move(const float& _dt, const float dir_x, const float dir_y);
	virtual void Update(const float& _dt);
	virtual void Render(sf::RenderTarget* _target);
};

#endif