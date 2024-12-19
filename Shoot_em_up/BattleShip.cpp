
#include "BattleShip.h"
#include "Game.h"
#include "RessourceManager.h"

Battleship::Battleship(Game& gameRef)
    : m_game(gameRef)
    , m_angle(0.f)
    , m_position{ 100.f, 300.f }
    , m_velocity{ 0.f, 0.f }
    , isAccelerating(false)
    , isTurningLeft(false)
    , isTurningRight(false)

{
    //E:\Visual Studio projet\SFML\Shoot_em_up\Shoot_em_up\Texture\Enemies\Battleship
    m_texture = m_game.getTextureCash().getTexture("Texture\\Enemies\\Battleship\\ShipBattleshipHull.png");
    m_sprite.setTexture(m_game.getTextureCash().getTexture("Texture\\Enemies\\Battleship\\ShipBattleshipHull.png"));
}

ObjectType Battleship::getObjectType() const
{
    return ObjectType::Enemy;
}
sf::FloatRect Battleship::getBounds() const
{
    return m_sprite.getGlobalBounds();
}

void Battleship::handleInput()
{
    isAccelerating = (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
    isTurningLeft = (sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
    isTurningRight = (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}
void Battleship:: update(float deltaTime)
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
void Battleship:: render(sf::RenderWindow& window)
{
    m_sprite.setRotation(m_angle * 180.f / 3.14f);
    sf::Vector2u textureSize = m_texture.getSize();
    m_sprite.setOrigin(static_cast<float> (textureSize.x / 2), static_cast<float> (textureSize.y / 2));
    m_sprite.setPosition(m_position.x, m_position.y);
    window.draw(m_sprite);
}
//IEnnemy::~IEnnemy()
//{}

