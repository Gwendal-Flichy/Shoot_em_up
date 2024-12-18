#include "Player.h"
#include "Game.h"

#include "Mymath.h"

#include "ResourceManager.h"

PlayerShip::PlayerShip(Game& gameRef) : 
    m_game(gameRef)
    ,m_angle(0.f)
    ,m_position{300.f, 300.f }
    ,m_velocity{0.f, 0.f }
    ,isAccelerating(false)
    ,isTurningLeft(false)
    ,isTurningRight(false)
    
{

    //m_texture.loadFromFile("C:\\Users\\gflichy\\source\\repos\\test_projet_SFML\\test_projet_SFML\\Truc.bmp");
    
    m_texture = m_game.getTextureCash().getTexture("Texture\\Player\\aircraft_1.png");
    m_sprite.setTexture(m_game.getTextureCash().getTexture("Texture\\Player\\aircraft_1.png"));

}

void PlayerShip::handleInput()
{
    isAccelerating = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    isTurningLeft = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    isTurningRight = (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

}

void PlayerShip::update(float deltaTime)
{

    if (isTurningLeft)
        m_angle -= 0.05f;
    if (isTurningRight)
        m_angle += 0.05f;

    Vec2 acceleration{ 0.f, 0.f };
    if (!isAccelerating)
        acceleration = -0.7f * m_velocity;
    if (isAccelerating)
        acceleration += Vec2{ std::cos(m_angle - 3.14f / 2.f),std::sin(m_angle - 3.14f / 2.f) }*100;


    m_position += m_velocity * deltaTime;

    m_velocity += acceleration * deltaTime;
    if (m_velocity.getlenght() > 200)
        m_velocity = m_velocity * (200 / m_velocity.getlenght());
}



void PlayerShip::render(sf::RenderWindow& window)
{

    m_sprite.setRotation(m_angle * 180 / 3.14);
    sf::Vector2u textureSize = m_texture.getSize();
    m_sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    m_sprite.setPosition(m_position.x,m_position.y);
    window.draw(m_sprite);


}

