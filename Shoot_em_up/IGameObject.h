#pragma once

#include <SFML/Graphics.hpp>

class IGameObject
{
public:

	virtual ~IGameObject() = default;


	//Game Loop:
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;



private:
};