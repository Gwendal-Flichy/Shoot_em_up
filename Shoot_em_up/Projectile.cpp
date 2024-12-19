#include "Projectile.h"
#include "Game.h"
#include <iostream>

#include "RessourceManager.h"

Projectile::Projectile(Game& gameRef, const std::string& texturePath, const ObjectType& Type, const Vec2& beginPosition={0,0}, float angle = 0, Vec2 velocity = {0,0}, int damage = 1, float lifeTime = 0) :
    m_game(gameRef)
    , m_texturePath(texturePath)
    , m_Type( Type )
    , m_beginPosition(beginPosition)
    , m_angle(angle)
    , m_velocity(velocity)
    , m_damage(damage)
    ,m_lifeTime(lifeTime)
    , currentPosition{ beginPosition }

{

    //m_texture.loadFromFile("C:\\Users\\gflichy\\source\\repos\\test_projet_SFML\\test_projet_SFML\\Truc.bmp");

    m_texture = m_game.getTextureCash().getTexture(m_texturePath);
    m_sprite.setTexture(m_game.getTextureCash().getTexture(m_texturePath));

}

void Projectile::handleInput()
{
}

void Projectile::update(float deltaTime)
{

    currentPosition += m_velocity * deltaTime;

    Vec2 maxDistance {currentPosition.x * currentPosition.x - m_beginPosition.x * m_beginPosition.x, currentPosition.y* currentPosition.y - m_beginPosition.y * m_beginPosition.y};
    if (maxDistance.getlenght() > m_lifeTime)
        std::cout << "POP\n";

}



void Projectile::render(sf::RenderWindow& window)
{

    m_sprite.setRotation(m_angle * 180.f / 3.14f);
    sf::Vector2u textureSize = m_texture.getSize();
    m_sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);
    m_sprite.setPosition(currentPosition.x, currentPosition.y);
    window.draw(m_sprite);


}


ObjectType Projectile::getObjectType() const
{
    return m_Type;
}
sf::FloatRect Projectile::getBounds() const
{
    return m_sprite.getGlobalBounds();
}