#include "Camera.h"

Camera::Camera()
{
	playerCamera = new sf::View(sf::Vector2f(640, 360), sf::Vector2f(1280, 720));
	playerCamera->setSize(1920, 1080);
}

Camera::~Camera()
{
	delete playerCamera;
}

void Camera::Update(sf::RenderTarget* _window, sf::Vector2f _center)
{
	SetView(_window, _center);
}

void Camera::SetView(sf::RenderTarget* _window, sf::Vector2f _center)
{
	_window->setView(*playerCamera);
	playerCamera->setCenter(_center);
}



