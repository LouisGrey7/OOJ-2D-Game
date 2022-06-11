#include "Game.h"


//Initializer Functions
void Game::InitWindow()
{

	sf::VideoMode windowBounds(1280, 720);
	unsigned framerateLimit = 120;
	
	this->window = new sf::RenderWindow(windowBounds, "SFML Platformer");
	this->window->setFramerateLimit(framerateLimit);
	this->window->setVerticalSyncEnabled(true);

}


//Constructor/Destructors
Game::Game()
{
	this->InitWindow();
	newScene = new Scene(128, 72);
	if (currentLevel == 1)
	{
		newScene->LoadScene("Scenes/Scene1.txt");
		SpawnEnemies();
	}

	
}

Game::~Game()
{
	delete this->window;

}

void Game::SpawnEnemies()
{
	for (int i = 0; i < newScene->m_enemySpawnTiles.size(); ++i)
	{
		enemies.push_back(new Enemies);
		enemies[i]->EnemyGetShape()->setPosition(newScene->m_enemySpawnTiles[i]->tileShape->getPosition());
	}

}

void Game::UnspawnEnemies()
{
	enemies.clear();
}

//Update

void Game::UpdateDt()
{
	//updates the delta time variable
	this->dt = dtClock.getElapsedTime().asSeconds();
	this->dtClock.restart();

}


void Game::Update()
{

	
	while (this->window->pollEvent(this->event))
	{
		//Exit Game
		if (this->event.type == sf::Event::Closed)
		{
			this->window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			//Enable gravity
			if (event.key.code == sf::Keyboard::E)
			{
				gravityEnabled = !gravityEnabled;
				std::cout << "gravityenabled" << gravityEnabled;
			}
			if (event.key.code == sf::Keyboard::L)
			{
				
				currentLevel = 2;
				newScene->UnloadScene();
				UnspawnEnemies();
				if (currentLevel == 2)
				{
					newScene->LoadScene("Scenes/Scene2.txt");
					SpawnEnemies();
				}
			}
			//Jump
			if (event.key.code == sf::Keyboard::Space)
			{
				if (newCharacter.currentJumpCount > 0)
				{
					newCharacter.GetCharacterShape()->move(sf::Vector2f(0.0f, -1.5f));
					newCharacter.charYVelocity = newCharacter.jumpHeight;

					newCharacter.currentJumpCount--;
					std::cout << "jump \n";
				}
			}
		}
	}

	//Win Tile Collision change level
	if (newScene->m_winTile->tileShape->getGlobalBounds().intersects(newCharacter.GetCharacterShape()->getGlobalBounds()))
	{
		std::cout << "hit \n";		
		newScene->UnloadScene();
		UnspawnEnemies();
		newScene->LoadScene("Scenes/Scene2.txt");
		SpawnEnemies();
	}

	//Character
	newCharacter.Update(dt, newScene->m_levelWallColliders);

	//Enemy
	for (auto* enemy : enemies)
	{
		enemy->Update(dt, newCharacter.GetCharacterPosition().x, newCharacter.GetCharacterPosition().y, newScene->m_levelWallColliders, newScene->m_patrolCollideTiles);
	}
	//Camera
	newCamera.Update(window, newCharacter.GetCharacterPosition());

	//UI
	newUI.Update(newCharacter.characterHealth, newCamera.playerCamera->getCenter());


	//Physics
	newPhysicsSystem.UpdateDynamicObject(&newCharacter, dt, gravityEnabled);

	for (auto* enemy : enemies)
	{
		newPhysicsSystem.UpdateDynamicEnemy(enemy, dt, gravityEnabled);
	}
}

void Game::Render()
{
	this->window->clear();

	
	newScene->Render(window);
	this->newCharacter.Render(window);
	for (auto* enemy : enemies)
	{
		enemy->Render(window);
	}
	newUI.Render(window);


	this->window->display();
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDt();
		this->Update();


		this->Render();
	}
}
