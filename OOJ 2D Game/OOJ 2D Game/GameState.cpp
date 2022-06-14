#include "GameState.h"

GameState::GameState(sf::Vector2f _centerScreen)
{

	if (m_buttonTex.loadFromFile("Sprites/MenuButton.png"))
	{
	}
	titleFont = new sf::Font();
	buttonFont = new sf::Font();
	if (!titleFont->loadFromFile("Fonts/RAVIE.ttf"))
	{
	}
	if (!buttonFont->loadFromFile("Fonts/RAVIE.ttf"))
	{
	}

	background = new sf::RectangleShape(sf::Vector2f(2000.0f,2000.0f));
	background->setFillColor(sf::Color::Cyan);
	background->setOrigin(sf::Vector2f(1000.0f, 1000.0f));


	m_titleText.setFont(*buttonFont);
	m_titleText.setCharacterSize(60);
	m_titleText.setFillColor(sf::Color::Red);
	m_titleText.setPosition(sf::Vector2f(_centerScreen.x - 230, _centerScreen.y - 300));
	m_titleText.setString("Jump Dash");

	m_winText.setFont(*buttonFont);
	m_winText.setCharacterSize(60);
	m_winText.setFillColor(sf::Color::Red);
	m_winText.setPosition(sf::Vector2f(_centerScreen.x - 230, _centerScreen.y - 300));
	m_winText.setString("You Win");

	for (int i = 0; i < uiElementCount; i++)
	{
		sf::RectangleShape* newButton = new sf::RectangleShape();
		newButton->setSize(sf::Vector2f(m_ButtonWidth, m_ButtonHeight));
		newButton->setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y + (i * m_ButtonHeight * 2 - 80)));
		newButton->setOrigin(sf::Vector2f(m_ButtonWidth / 2, m_ButtonHeight / 2));
		newButton->setFillColor(sf::Color::Cyan);
		newButton->setTexture(&m_buttonTex);

		sf::Text buttonText;
		buttonText.setFont(*buttonFont);
		buttonText.setCharacterSize(30);
		buttonText.setFillColor(sf::Color::Red);
		buttonText.setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y + (i * m_ButtonHeight * 2 - 80)));
		buttonText.setOrigin(sf::Vector2f(m_ButtonWidth / 2 - 4, m_ButtonHeight / 2 - 10));
		buttonText.setString("Button Text");

		m_UITextElements.push_back(buttonText);

		m_UIElements.push_back(newButton);
	}
	m_UITextElements[0].setString("Start Game");
	m_UITextElements[1].setString("Debug Mode");
	m_UITextElements[2].setString("Rules");
	m_UITextElements[3].setString("Quit Game");
	m_UITextElements[4].setString("Back");
}

GameState::~GameState()
{
	for (int i = 0; i < m_UIElements.size(); i++)
	{
		delete this->m_UIElements[i];
	}
}

void GameState::Render(sf::RenderWindow* _window)
{
	_window->draw(*background);
	for (int i = 0; i < m_UIElements.size() - 1; i++)
	{
		_window->draw(*m_UIElements[i]);
		
	}
	for (int i = 0; i < m_UITextElements.size() - 1; i++)
	{
		_window->draw(m_UITextElements[i]);
	}

	_window->draw(m_titleText);

}

void GameState::Update(sf::RenderWindow* _window, sf::Vector2f _camerapos)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*_window);
	sf::Vector2f worldPos = _window->mapPixelToCoords(pixelPos);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_UIElements[0]->getGlobalBounds().contains(sf::Vector2f(worldPos)))
		{

			m_currentState = currentGameState::currentState_Playing;

		}
		if (m_UIElements[1]->getGlobalBounds().contains(sf::Vector2f(worldPos)))
		{

			m_currentState = currentGameState::currentState_Debug;

		}
		if (m_UIElements[2]->getGlobalBounds().contains(sf::Vector2f(worldPos)))
		{

		}
		if (m_UIElements[3]->getGlobalBounds().contains(sf::Vector2f(worldPos)))
		{
			_window->close();
		}
	}
}

void GameState::WinScreenRender(sf::RenderWindow* _window)
{
	_window->draw(*background);
	_window->draw(*m_UIElements[4]);
	_window->draw(m_UITextElements[4]);
	_window->draw(m_winText);
}

void GameState::WinScreenUpdate(sf::RenderWindow* _window, sf::Vector2f _centerScreen)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*_window);
	sf::Vector2f worldPos = _window->mapPixelToCoords(pixelPos);
	m_winText.setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y));
	background->setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y));
	m_UIElements[4]->setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y));
	m_UITextElements[4].setPosition(sf::Vector2f(_centerScreen.x, _centerScreen.y));
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_UIElements[4]->getGlobalBounds().contains(sf::Vector2f(worldPos)))
		{
			std::cout << "win \n";
			m_currentState = currentGameState::currentState_Menu;
		}
	}
}
