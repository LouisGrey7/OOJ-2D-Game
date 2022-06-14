#pragma once
#include "SFML/Graphics.hpp"
#include "Tiles.h"
#include <fstream>
#include <iostream>

class Scene
{
private:
public:
	//Variables
	sf::RectangleShape* background;
	sf::Texture backgroundTex;
	int m_currentLevel = 0;

	float tileSize = 100.0f;

	static const int m_levelWidth = 100;
	static const int m_levelHeight = 100;

	std::vector<Tiles*> m_levelTiles;
	std::vector<Tiles*> m_enemySpawnTiles;
	std::vector<Tiles*> m_killTiles;


	char levelArray[m_levelWidth][m_levelHeight];

	std::vector<sf::FloatRect> m_levelWallColliders;
	std::vector<sf::FloatRect> m_patrolCollideTiles;

	Tiles* newTile;
	Tiles* m_winTile;
	Tiles* charSpawnTile;

	//Initialization


	//Constructor/Destructors
	
	Scene(int _levelWidth, int _levelHeight);
	virtual ~Scene();


	//Functions
	void LoadScene(std::string _filepath);
	void UnloadScene();

	//Update


	//Render
	void Render(sf::RenderTarget* _window);

	//Accessors
	
};

