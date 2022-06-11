#include "Character.h"

void Character::InitCharacter()
{
	charShape = new sf::RectangleShape(charSize);
	charShape->setFillColor(sf::Color::White);
	charShape->setPosition(150.0f, 1250.0f);
	charShape->setOrigin(charSize.x / 2, charSize.y / 2);

	charTex.loadFromFile("Sprites/MainCharacter.png");

	charShape->setTexture(&charTex);

}

Character::Character()
{
	InitCharacter();
}

Character::~Character()
{
	delete charShape;
}

void Character::Move(float _dt, std::vector<sf::FloatRect> _Collisions)
{
	//move on y axis
	charShape->move(0, charMoveVec.y * charSpeed * _dt);
	//collide on the y axis
	for (int i = 0; i < _Collisions.size(); i++)
	{
		if (charShape->getGlobalBounds().intersects(_Collisions[i]))
		{
			colliding = true;
			charYVelocity = 0.0f;
			currentJumpCount = maxJumpCount;
			Collisions::ResolveYCollision(charShape, _Collisions[i], true);
		}
		else
		{
			colliding = false;
		}
	}

	//move on X axis
	charShape->move(charMoveVec.x * charSpeed * _dt, 0);
	//collide on the x axis
	for (int i = 0; i < _Collisions.size(); i++)
	{
		if (charShape->getGlobalBounds().intersects(_Collisions[i]))
		{
			Collisions::ResolveXCollision(charShape, _Collisions[i], true);
		}
	}

}

void Character::CharacterInputUpdate(float _dt, std::vector<sf::FloatRect> _Collisions)
{
	charMoveVec = sf::Vector2f(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//charMoveVec.y = -1.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//charMoveVec.y = 1.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		charMoveVec.x = -1.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		charMoveVec.x = 1.0f;
		
	}
	
	Move(_dt, _Collisions);
}

void Character::Update(float _dt, std::vector<sf::FloatRect> _Collisions)
{
	CharacterInputUpdate(_dt, _Collisions);
	charPos = charShape->getPosition();


}

void Character::Render(sf::RenderTarget* _window)
{
	_window->draw(*charShape);
}

sf::RectangleShape* Character::GetCharacterShape()
{
	return charShape;
}

sf::Vector2f Character::GetCharacterPosition()
{
	return charPos;
}
