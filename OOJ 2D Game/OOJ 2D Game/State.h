#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State
{
private:



protected:
	//Variables
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	//Constructor Destructor
	State(sf::RenderWindow* _window);
	virtual ~State();

	const bool& getQuit() const;

	//Functions

	virtual void CheckForQuit();

	virtual void EndState() = 0;

	virtual void UpdateKeybinds(const float& _dt) = 0;
	virtual void Update(const float& _dt) = 0;
	virtual void Render(sf::RenderTarget* _target = nullptr) = 0;

};

#endif