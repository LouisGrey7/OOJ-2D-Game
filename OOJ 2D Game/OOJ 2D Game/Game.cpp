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
	newGameState = new GameState(newCharacter.GetCharacterPosition());
	newScene = new Scene(128, 72);
	newScene->LoadScene("Scenes/Scene1.txt");
	SpawnChar();
	SpawnEnemies();
	
}

Game::~Game()
{
	delete this->window;

}

//Functions
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

void Game::SpawnChar()
{
	newCharacter.GetCharacterShape()->setPosition(newScene->charSpawnTile->tileShape->getPosition());
}

void Game::KillTile()
{
	for (auto* tile : newScene->m_killTiles)
	{
		if (tile->tileShape->getGlobalBounds().intersects(newCharacter.GetCharacterShape()->getGlobalBounds()))
		{
			SpawnChar();

		}
	}
}

void Game::WinTile()
{
	if (newScene->m_winTile->tileShape->getGlobalBounds().intersects(newCharacter.GetCharacterShape()->getGlobalBounds()))
	{
		newScene->UnloadScene();
		UnspawnEnemies();

		if (currentLevel == 1)
		{
			newScene->LoadScene("Scenes/Scene2.txt");
			SpawnEnemies();
			SpawnChar();
			currentLevel++;
			std::cout << currentLevel << "\n";
			
		}
		else if (currentLevel == 2)
		{
			std::cout << "hit \n";		
			newGameState->m_currentState = newGameState->currentState_Win;
		}
	}
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

	if (newGameState->m_currentState == newGameState->currentState_Menu)
	{
		//Camera
		while (this->window->pollEvent(this->event))
		{
			if (this->event.type == sf::Event::Closed)
			{
				this->window->close();
			}
			newCamera.Update(window, newCharacter.GetCharacterPosition());
			newGameState->Update(window, newCharacter.GetCharacterPosition());
		}
	}
	if (newGameState->m_currentState == newGameState->currentState_Rules)
	{

	}
	if (newGameState->m_currentState == newGameState->currentState_Playing)
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
				//Jump
				if (event.key.code == sf::Keyboard::Space)
				{
					if (newCharacter.currentJumpCount > 0)
					{
						newCharacter.GetCharacterShape()->move(sf::Vector2f(0.0f, -1.5f));
						newCharacter.charYVelocity = newCharacter.jumpHeight;
						newCharacter.currentJumpCount--;

					}
				}
				//Dash
				if (event.key.code == sf::Keyboard::LShift)
				{
					newCharacter.charXVelocity = newCharacter.dashDistance;
				}
			}
		}

		//Tile Collision
		KillTile();
		WinTile();

		//Character
		newCharacter.Update(dt, newScene->m_levelWallColliders);

		//Camera
		newCamera.Update(window, newCharacter.GetCharacterPosition());

		//Game State
		newGameState->Update(window, newCamera.playerCamera->getSize());

		//Enemy
		for (auto* enemy : enemies)
		{
			enemy->Update(dt, newCharacter.GetCharacterPosition().x, newCharacter.GetCharacterPosition().y, newScene->m_levelWallColliders, newScene->m_patrolCollideTiles);
			if (newCharacter.GetCharacterShape()->getGlobalBounds().intersects(enemy->EnemyGetShape()->getGlobalBounds()))
			{
				SpawnChar();
			}
		}
	

		//Physics
		newPhysicsSystem.UpdateDynamicObject(&newCharacter, dt, gravityEnabled);

		for (auto* enemy : enemies)
		{
			newPhysicsSystem.UpdateDynamicEnemy(enemy, dt, gravityEnabled);
		}

	}
	if (newGameState->m_currentState == newGameState->currentState_Win)
	{
		while (this->window->pollEvent(this->event))
		{
			if (this->event.type == sf::Event::Closed)
			{
				this->window->close();
			}
			newCamera.Update(window, newCharacter.GetCharacterPosition());
			newGameState->WinScreenUpdate(window, newCamera.playerCamera->getCenter());
		}
	}
	if (newGameState->m_currentState == newGameState->currentState_Debug)
	{

	}
}

void Game::Render()
{
	this->window->clear();
	if (newGameState->m_currentState == newGameState->currentState_Menu)
	{
		newGameState->Render(window);
	}
	if (newGameState->m_currentState == newGameState->currentState_Playing)
	{
		newGameState->Render(window);
		newScene->Render(window);
		this->newCharacter.Render(window);
		for (auto* enemy : enemies)
		{
			enemy->Render(window);
		}
	}
	if (newGameState->m_currentState == newGameState->currentState_Win)
	{
		newGameState->WinScreenRender(window);
	}


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
