#pragma once
#include "SFML/Graphics.hpp"

enum TileType
{
	TILE_GROUND,
	TILE_DEEPGROUND,
	TILE_WATER,
	TILE_WATERSURFACE,
	TILE_WINTILE,
	TILE_PATROLCOLLIDETILE,
	TILE_ENEMYSPAWN,
	TILE_CHARSPAWNTILE,
	TILE_KILLTILE
};


class Tiles
{

private:
	//Variables
	

	//Initialization



public:

	//Variables
	sf::RectangleShape* tileShape;
	sf::FloatRect AABB;
	sf::Texture groundTex;
	sf::Texture deepGroundTex;
	sf::Texture waterTex;
	sf::Texture waterSurfaceTex;
	sf::Texture winTileTex;

	TileType tileType;

	sf::Vector2f tileSize = sf::Vector2f(100.0f,100.0f);

	//Constructor/Destructors
	Tiles(TileType _type);
	virtual ~Tiles();


	//Functions

	//Update


	//Render


	//Accessors
};

