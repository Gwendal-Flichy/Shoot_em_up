#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
namespace sf { class RenderWindow; }

enum class ObjectType
{
    Player
   ,Enemy
   ,ProjectileP
   ,ProjectileE

};

class IGameObject
{
public:
    virtual ~IGameObject() = default;

    
    virtual ObjectType  getObjectType() const=0;
    virtual sf::FloatRect getBounds() const=0;

    virtual void handleInput() = 0;

    virtual void update(float deltaTime) = 0;


    virtual void render(sf::RenderWindow& window) = 0;

};

