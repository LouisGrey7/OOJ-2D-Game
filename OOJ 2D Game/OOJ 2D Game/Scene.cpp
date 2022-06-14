#include "Scene.h"

Scene::Scene(int _levelWidth, int _levelHeight)
{
	background = new sf::RectangleShape(sf::Vector2f(10000.0f, 10000.0f));
	background->setOrigin(sf::Vector2f(960.0f, 540.0f));
	background->setFillColor(sf::Color::Cyan);
	background->setPosition(sf::Vector2f(0.0f, 0.0f));
	background->setTexture(&backgroundTex);

}

Scene::~Scene()
{
}

void Scene::LoadScene(std::string _filepath)
{
	// fstream object.
	// this fstream object holds the data that is read from the file.
	std::fstream loadFileStream;
	loadFileStream.open(_filepath, std::ios::in);
	std::string loadFileString;
	int lineCount = 0;

	if (loadFileStream.is_open())
	{
		while (std::getline(loadFileStream, loadFileString))
		{
			for (int i = 0; i < loadFileString.size(); i++)
			{
				levelArray[lineCount][i] = loadFileString[i];
			}

			lineCount++;

		}

		loadFileStream.close();
	}

	for (int x = 0; x < m_levelWidth; x++)
	{
		for (int y = 0; y < m_levelHeight; y++)
		{
			//Placing Ground
			if (levelArray[y][x] == 'G')
			{
				newTile = new Tiles(TileType::TILE_GROUND);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);

				m_levelWallColliders.push_back(newTile->tileShape->getGlobalBounds());
			}
			if (levelArray[y][x] == 'D')
			{
				newTile = new Tiles(TileType::TILE_DEEPGROUND);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);

				m_levelWallColliders.push_back(newTile->tileShape->getGlobalBounds());
			}
			if (levelArray[y][x] == 'W')
			{
				newTile = new Tiles(TileType::TILE_WATER);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);
			}
			if (levelArray[y][x] == 'S')
			{
				newTile = new Tiles(TileType::TILE_WATERSURFACE);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);
			}
			if (levelArray[y][x] == '!')
			{
				newTile = new Tiles(TileType::TILE_WINTILE);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);

				m_winTile = newTile;
			}
			if (levelArray[y][x] == 'P')
			{
				newTile = new Tiles(TileType::TILE_PATROLCOLLIDETILE);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);

				m_patrolCollideTiles.push_back(newTile->tileShape->getGlobalBounds());

			}
			if (levelArray[y][x] == 'X')
			{
				newTile = new Tiles(TileType::TILE_ENEMYSPAWN);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_enemySpawnTiles.push_back(newTile);

			}
			if (levelArray[y][x] == 'R')
			{
				newTile = new Tiles(TileType::TILE_CHARSPAWNTILE);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_levelTiles.push_back(newTile);

				charSpawnTile = newTile;

			}
			if (levelArray[y][x] == 'K')
			{
				newTile = new Tiles(TileType::TILE_KILLTILE);
				newTile->tileShape->setPosition(sf::Vector2f(x * tileSize, y * tileSize));

				m_killTiles.push_back(newTile);


			}
		}
	}
}

void Scene::UnloadScene()
{
	m_levelTiles.clear();
	m_enemySpawnTiles.clear();
	m_levelWallColliders.clear();
	m_patrolCollideTiles.clear();
	delete newTile;
	delete m_winTile;
}



void Scene::Render(sf::RenderTarget* _window)
{
	_window->draw(*background);
	for (int i = 0; i < m_levelTiles.size(); i++)
	{
		_window->draw(*m_levelTiles[i]->tileShape);
	}
	for (int i = 0; i < m_enemySpawnTiles.size(); i++)
	{
		_window->draw(*m_enemySpawnTiles[i]->tileShape);
	}
	for (int i = 0; i < m_killTiles.size(); i++)
	{
		_window->draw(*m_killTiles[i]->tileShape);
	}
}
