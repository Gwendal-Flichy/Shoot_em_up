#pragma once

#include "IGameObject.h"

class Player: public IGameObject
{
public:
	Player();
		
	void handleInput() override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	int  m_vie;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	sf::Vector2f m_Position;
};
