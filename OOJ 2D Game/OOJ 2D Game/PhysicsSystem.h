#pragma once
#include "Character.h"
#include "Enemies.h"
#include <iostream>

class PhysicsSystem
{
private:
	//Variables


	//Initialization



public:
	//Variables
	float GravityValue = 22.0f;

	//Constructor/Destructors
	PhysicsSystem();
	~PhysicsSystem();

	//Functions


	//Update
	void UpdateDynamicObject(Character* _playerChar, float _dt, bool _enabled);
	void UpdateDynamicEnemy(Enemies* _enemy, float _dt, bool _enabled);
	//Render


	//Accessors

};

