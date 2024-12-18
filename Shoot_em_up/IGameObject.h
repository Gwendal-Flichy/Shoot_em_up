#pragma once
#include <SFML/Graphics.hpp>

namespace sf { class RenderWindow; }

struct Vec2
{

    float x;
    float y;
    float getlenght();
    Vec2& operator+=(const Vec2& op1);
    Vec2& operator-=(const Vec2& op1);
};

struct AABB
{
    Vec2 min;
    Vec2 max;

};

class IGameObject
{
public:
    virtual ~IGameObject() = default;


    virtual void handleInput() = 0;

    virtual void update(float deltaTime) = 0;


    virtual void render(sf::RenderWindow& window) = 0;





private:

};
