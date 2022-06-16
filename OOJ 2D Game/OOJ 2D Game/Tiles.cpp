#include "Tiles.h"

Tiles::Tiles(TileType _type)
{
	tileShape = new sf::RectangleShape();

	tileShape->setSize(sf::Vector2f(tileSize));
	tileShape->setOrigin(sf::Vector2f(tileSize.x / 2, tileSize.y /2));
	AABB = tileShape->getGlobalBounds();

	if (!groundTex.loadFromFile("Sprites/TileGround.png"))
	{ }
	if (!deepGroundTex.loadFromFile("Sprites/TileDeepGround.png"))
	{ }
	if (!waterTex.loadFromFile("Sprites/TileWater.png"))
	{ }
	if (!waterSurfaceTex.loadFromFile("Sprites/TileWaterSurface.png"))
	{ }
	if (!winTileTex.loadFromFile("Sprites/TileWin.png"))
	{ }

	tileType = _type;

	switch (_type)
	{
	case TILE_GROUND:
		tileShape->setTexture(&groundTex);
		break;
	case TILE_DEEPGROUND:
		tileShape->setTexture(&deepGroundTex);
		break;
	case TILE_WATER:
		tileShape->setTexture(&waterTex);
		break;
	case TILE_WATERSURFACE:
		tileShape->setTexture(&waterSurfaceTex);
		break;
	case TILE_WINTILE:
		tileShape->setTexture(&winTileTex);
		break;
	case TILE_PATROLCOLLIDETILE:
		tileShape->setFillColor(sf::Color::Cyan);
		break;
	case TILE_ENEMYSPAWN:
		tileShape->setFillColor(sf::Color::Cyan);
		break;
	case TILE_CHARSPAWNTILE:
		tileShape->setFillColor(sf::Color::Cyan);
		break;
	case TILE_KILLTILE:
		tileShape->setFillColor(sf::Color::Cyan);
		break;
	default:
		break;
	}
}

Tiles::~Tiles()
{
	delete tileShape;
}




