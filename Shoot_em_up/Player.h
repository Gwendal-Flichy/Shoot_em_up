#pragma once

#include "IGameObject.h"
#include "Mymath.h"
#include "FireMode.h"

class Game;


class PlayerShip : public IGameObject
{
public:
    PlayerShip(Game& gameRef);


    void handleInput() override;

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;

    ObjectType getObjectType() const override;
    sf::FloatRect getBounds() const override;
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    bool isAccelerating;
    bool isTurningLeft;
    bool isTurningRight;
    bool isDecelerate;
    bool isFire;
    float m_angle;


    Vec2 m_position;
    Vec2 m_velocity;
    Game& m_game;
    FireMode fire;
};

