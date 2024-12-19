#pragma once
#include "IGameObject.h"
#include "Mymath.h"


class Game;

class Projectile : public IGameObject
{
public:
    Projectile(Game& gameRef, const std::string& texturePath, const ObjectType& Type, const Vec2& beginPosition, float angle, Vec2 velocity, int damage, float lifeTime);

    void handleInput() override;

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;
    ObjectType getObjectType() const override;
    
    sf::FloatRect getBounds() const override;
    

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    std::string m_texturePath;

    ObjectType m_Type;

    float m_angle;
    int m_damage;
    float m_lifeTime;
    Vec2 m_beginPosition;
    Vec2 currentPosition;
    Vec2 m_velocity;
    Game& m_game;
};