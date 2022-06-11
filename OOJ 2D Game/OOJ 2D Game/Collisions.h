#pragma once
#include "SFML/Graphics.hpp"

static class Collisions
{
public:
	//Functions
	static void ResolveXCollision(sf::Shape* _objA, sf::FloatRect _objB, bool _secondobjwall)
	{
		sf::Vector2f entityACenter = { (_objA->getGlobalBounds().left + _objA->getGlobalBounds().width / 2.0f),
										(_objA->getGlobalBounds().top + _objA->getGlobalBounds().height / 2.0f) };

		sf::Vector2f entityBCenter = { (_objB.left + _objB.width / 2.0f),
										(_objB.top + _objB.height / 2.0f) };

		if (entityACenter.x <= entityBCenter.x)
		{
			float offset = -(_objA->getGlobalBounds().left + _objA->getGlobalBounds().width - _objB.left);
			_objA->move(offset, 0);
		}

		if (entityACenter.x >= entityBCenter.x)
		{
			float offset = (_objB.left + _objB.width) - _objA->getGlobalBounds().left;
			_objA->move(offset, 0);
		}
	}

	static void ResolveYCollision(sf::Shape* _objA, sf::FloatRect _objB, bool _secondobjwall)
	{
		sf::Vector2f entityACenter = { (_objA->getGlobalBounds().left + _objA->getGlobalBounds().width / 2.0f),
										(_objA->getGlobalBounds().top + _objA->getGlobalBounds().height / 2.0f) };

		sf::Vector2f entityBCenter = { (_objB.left + _objB.width / 2.0f),
										(_objB.top + _objB.height / 2.0f) };
		// underneath the tile
		if (entityACenter.y <= entityBCenter.y)
		{
			float offset = -(_objA->getGlobalBounds().top + _objA->getGlobalBounds().height - _objB.top);
			_objA->move(0, offset);
		}

		// above the tile
		if (entityACenter.y >= entityBCenter.y)
		{
			float offset = (_objB.top + _objB.height) - _objA->getGlobalBounds().top;
			_objA->move(0, offset);
		}
	}
};

