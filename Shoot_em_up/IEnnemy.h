#pragma once
#include "IGameObject.h"

class IEnnemy : public IGameObject
{
public:
	virtual ~IEnnemy() = default;

	void handleInput() ;
	void update(float deltaTime) ;
	void render(sf::RenderWindow& window) ;
private:
};