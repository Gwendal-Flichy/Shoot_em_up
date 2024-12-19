#pragma once
#include <SFML/Graphics.hpp>

namespace sf { class RenderWindow; }



class IGameObject
{
public:
    virtual ~IGameObject() = default;


    virtual void handleInput() = 0;

    virtual void update(float deltaTime) = 0;


    virtual void render(sf::RenderWindow& window) = 0;





private:

};
