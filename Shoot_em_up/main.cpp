#include <SFML/Graphics.hpp>
#include<iostream>
#include <vector>
#include "Player.h"

int main()
{
    bool Activate = false;
    int x = 800;
    int y = 800;
    sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
    window.setFramerateLimit(60);

    //float angle = 0.f;
    //float AngularVelocity = 40.f;
    //int PositionXHelicopter = 400;
    //int PositionYHelicopter = 400;
    //int CenterXRotor = 22;
    //int CenterYRotor = 35;

    ///*sf::RectangleShape rectangle(sf::Vector2f(static_cast<float> (x), static_cast<float> (y)));
    //rectangle.setFillColor(sf::Color::Green);*/

    //sf::Texture Rotor;
    //Rotor.loadFromFile("Texture/Player/chopper-44x99.png");
    //sf::Sprite spriteRotor;
    //spriteRotor.setTexture(Rotor);
    //spriteRotor.setTextureRect(sf::IntRect(132, 0, 96, 98));
    //spriteRotor.setOrigin(48, 49);
    //spriteRotor.setPosition(PositionXHelicopter + CenterXRotor, PositionYHelicopter + CenterYRotor);
    ///*spriteRotor.setPosition(374, 387);*/


    //sf::Texture Helicopter;
    //Helicopter.loadFromFile("Texture/Player/chopper-44x99.png");
    //sf::Sprite spriteHelicopter;
    //spriteHelicopter.setTexture(Helicopter);
    //spriteHelicopter.setTextureRect(sf::IntRect(0, 100, 43, 98));
    ///*spriteHelicopter.setOrigin(22, 33);*/
    //spriteHelicopter.setPosition(PositionXHelicopter, PositionYHelicopter);
    //float HelicopterSpeed = 300.f;

    Player player;
    

    
    sf::Texture HelicopterEnnemi;
    HelicopterEnnemi.loadFromFile("Texture/Player/chopper-44x99.png");
    sf::Sprite spriteHelicopterEnnemi;
    spriteHelicopterEnnemi.setTexture(HelicopterEnnemi);
    spriteHelicopterEnnemi.setTextureRect(sf::IntRect(44, 0, 44, 99));
    spriteHelicopterEnnemi.setPosition(0, PositionYHelicopter);

    struct Ennemi
    {
        bool Activate = false;
    };
    

    sf::Texture Bullet;
    Bullet.loadFromFile("Texture/Shot/M484BulletCollection1.png");
    /*sf::Sprite spriteBullet;
    spriteBullet.setTexture(Bullet);*/
    /*spriteHelicopter.setOrigin(22, 33);*/
    /*spriteBullet.setPosition(PositionxHelicopter, PositionyHelicopter);*/

    //CHANGER LA TEXTURE
    // Configuration du système de tir
    struct Projectile
    {
        sf::Sprite spriteBullet;
        bool isActive = true;
    };

    std::vector<Projectile> projectiles(30); // Pool de projectiles
    float shootCooldown = 0.25f;
    float timeSinceLastShot = shootCooldown;

    // Initialisation des projectiles
    for (auto& projectile : projectiles)
    {
        projectile.spriteBullet.setTexture(Bullet);
        projectile.spriteBullet.setTextureRect(sf::IntRect(401,216, 8,13));
        /*projectile.spriteBullet.setOrigin(Bullet.getSize().x / 2.f,
            Bullet.getSize().y / 2.f);
        projectile.spriteBullet.setScale(0.5f, 0.5f);*/
    }

    sf::Clock clockBullet;
    while (window.isOpen())
    {
        float deltaTime = clockBullet.restart().asSeconds();
        timeSinceLastShot += deltaTime;
        
        window.clear();

        //input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle = angle + 0.01f;
        spriteRotor.setRotation(-AngularVelocity * (angle * 180 / 3.14));


        spriteHelicopterEnnemi.move(2, 0);

        if (spriteHelicopterEnnemi.getGlobalBounds().intersects(spriteHelicopter.getGlobalBounds()))
            Activate = true;

        if (!Activate)
            window.draw(spriteHelicopterEnnemi);




        sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window est un sf::Window

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spriteHelicopter.getPosition().x > 43)
        {
            // la touche "flèche gauche" est enfoncée : on bouge le rectangle
            spriteHelicopter.move(-HelicopterSpeed * deltaTime, 0);
            spriteRotor.move(-HelicopterSpeed * deltaTime, 0);


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spriteHelicopter.getPosition().x < x - 85)
        {
            // la touche "flèche droite" est enfoncée : on bouge le rectangle
            spriteHelicopter.move(HelicopterSpeed * deltaTime, 0);
            spriteRotor.move(HelicopterSpeed * deltaTime, 0);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spriteHelicopter.getPosition().y > 29)
        {
            // la touche "flèche haut" est enfoncée : on bouge le rectangle
            spriteHelicopter.move(0, -HelicopterSpeed * deltaTime);
            spriteRotor.move(0, -HelicopterSpeed * deltaTime);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spriteHelicopter.getPosition().y < y - 105)
        {
            // la touche "flèche bas" est enfoncée : on bouge le rectangle
            spriteHelicopter.move(0.f, HelicopterSpeed * deltaTime);
            spriteRotor.move(0.f, HelicopterSpeed * deltaTime);

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && timeSinceLastShot >= shootCooldown)
        {
            int projectilesShot = 0;
            for (auto& projectile : projectiles)
            {
                if (!projectile.isActive && projectilesShot < 2)
                {
                    projectile.isActive = true;

                    // Position du premier projectile (gauche)
                    if (projectilesShot == 0)
                    {
                        projectile.spriteBullet.setPosition(
                            spriteHelicopter.getPosition().x -2 ,
                            spriteHelicopter.getPosition().y + 20
                        );
                    }
                    // Position du deuxième projectile (droite)
                    else
                    {
                        projectile.spriteBullet.setPosition(
                            spriteHelicopter.getPosition().x + 37,
                            spriteHelicopter.getPosition().y + 20
                        );
                    }
                    projectilesShot++;

                    // Reset le cooldown après avoir tiré les deux projectiles
                    if (projectilesShot == 2)
                    {
                        timeSinceLastShot = 0;
                        break;
                    }
                }
            }
        }

        // Mise à jour des projectiles
        for (auto& projectile : projectiles)
        {
            if (projectile.isActive)
            {
                // Déplacement du projectile
                projectile.spriteBullet.move(0, -400.f * deltaTime);

                // Désactivation si hors écran
                if (projectile.spriteBullet.getPosition().y < -50.f)
                {
                    projectile.isActive = false;
                }
            }
        }

        //if (localPosition.x)
        //{
        //    angle = angle + 5.f;
        //    spriteHelicopter.setRotation(localPosition.x);
        //   /* spriteRotor.setRotation(localPosition.x);*/

        //}
        //if (localPosition.y)
        //{
        //    angle = angle + 5.f;
        //    spriteHelicopter.setRotation(localPosition.y);
        //    /*spriteRotor.setRotation(localPosition.y);*/

        //}
       
        for (const auto& projectile : projectiles)
        {
            if (projectile.isActive)
            {
                window.draw(projectile.spriteBullet);
            }
        }
        
        window.draw(spriteHelicopter);
        window.draw(spriteRotor);
    

        window.display();
    }

    return 0;
}
//Pour la detection de collision on utilise un design pattern strategy
// Pour surcharger un operator += le faire dans la fonction membre avec
// friend class
//throw std::runtime_error("Try to remove non existing");
// faire une fonction destroy
//implémenter les types des objets(ennemi, perso etc...)
//implémenter un take dammage et initialiser les points de vies
//implémenter 2 classe EnnemyFireball et PlayerFireball pour régler les problèmes de collisions de l'entité et la fireball