#pragma once
#include "IGameObject.h"



class Game;

class PlayerShip : public IGameObject
{
public:
    PlayerShip(Game& gameRef);

    void handleInput() override;

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    bool isAccelerating;
    bool isTurningLeft;
    bool isTurningRight;
    bool isDecelerate;

    float m_angle;

    Vec2 m_position;
    Vec2 m_velocity;
    Game& m_game;
};