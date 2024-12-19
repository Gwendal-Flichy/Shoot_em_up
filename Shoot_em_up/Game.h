#pragma once

#include "vector"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class IGameObject;

class Game
{
public:
    friend class PlayerShip;
    Game();

    void handleInput();

    void update(float deltaTime);

    void render();

    void run();

    TextureCash& getTextureCash();



private:
    sf::RenderWindow m_window;
    std::vector<IGameObject*> m_allGameObject;
    TextureCash m_allTextureCash;
};