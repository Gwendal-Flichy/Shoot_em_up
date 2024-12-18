#include "Player.h"

float angle() { return 0.f; } 
float AngularVelocity() { return 40.f; } 
int PositionXHelicopter() { return 400; } 
int PositionYHelicopter() { return 400; }
int CenterXRotor() { return 22; }
int CenterYRotor() { return 35; }
float HelicopterSpeed() { return 300.f; }

Player::Player()
	:m_vie()
	, m_Sprite()
	, m_Texture()
	, m_Position()
{
    sf::Texture Rotor;
    Rotor.loadFromFile("Texture/Player/chopper-44x99.png");
    sf::Sprite spriteRotor;
    spriteRotor.setTexture(Rotor);
    spriteRotor.setTextureRect(sf::IntRect(132, 0, 96, 98));
    spriteRotor.setOrigin(48, 49);
    spriteRotor.setPosition(PositionXHelicopter() + CenterXRotor(), PositionYHelicopter() + CenterYRotor());

    sf::Texture Helicopter;
    Helicopter.loadFromFile("Texture/Player/chopper-44x99.png");
    sf::Sprite spriteHelicopter;
    spriteHelicopter.setTexture(Helicopter);
    spriteHelicopter.setTextureRect(sf::IntRect(0, 100, 43, 98));
    /*spriteHelicopter.setOrigin(22, 33);*/
    spriteHelicopter.setPosition(PositionXHelicopter(), PositionYHelicopter());
    
}

void Player::handleInput()
{

}
void Player::update()
{

}
void Player::render(sf::RenderWindow& window)
{

}