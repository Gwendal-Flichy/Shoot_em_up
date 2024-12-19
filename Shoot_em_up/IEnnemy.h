#pragma once
#include "IGameObject.h"

class IEnnemy : public IGameObject
{
public:
	virtual ~IEnnemy() = default;

	virtual ObjectType getObjectType() const=0;
	virtual sf::FloatRect getBounds() const = 0;

	virtual void handleInput()=0 ;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

private:
};