#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem()
{
}

PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::UpdateDynamicObject(Character* _playerChar, float _dt, bool _enabled)
{

	if (_enabled)
	{
		if (!_playerChar->colliding)
		{
			
			_playerChar->charYVelocity += GravityValue * _dt;
			

			_playerChar->GetCharacterShape()->move(sf::Vector2f(0, _playerChar->charYVelocity));
		}
	}
}

void PhysicsSystem::UpdateDynamicEnemy(Enemies* _enemy, float _dt, bool _enabled)
{

	if (_enabled)
	{
		if (!_enemy->colliding)
		{

			_enemy->enemyYVelocity += GravityValue * _dt;


			_enemy->EnemyGetShape()->move(sf::Vector2f(0, _enemy->enemyYVelocity));
		}
	}
}
