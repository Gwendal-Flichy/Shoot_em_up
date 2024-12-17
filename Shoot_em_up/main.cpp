#include <SFML/Graphics.hpp>
#include<iostream>
#include <vector>

int main()
{
    bool Activate = false;
    int x = 800;
    int y = 800;
    sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
    window.setFramerateLimit(60);

    float angle = 0.f;
    float AngularVelocity = 40.f;
    int PositionXHelicopter = 400;
    int PositionYHelicopter = 400;
    int CenterXRotor = 22;
    int CenterYRotor = 35;

    sf::Texture Rotor;
    Rotor.loadFromFile("Texture/Player/chopper-44x99.png");
    sf::Sprite spriteRotor;
    spriteRotor.setTexture(Rotor);
    spriteRotor.setTextureRect(sf::IntRect(132, 0, 96, 98));
    spriteRotor.setOrigin(48, 49);
    spriteRotor.setPosition(PositionXHelicopter + CenterXRotor, PositionYHelicopter + CenterYRotor);
    /*spriteRotor.setPosition(374, 387);*/


    sf::Texture Helicopter;
    Helicopter.loadFromFile("Texture/Player/chopper-44x99.png");
    sf::Sprite spriteHelicopter;
    spriteHelicopter.setTexture(Helicopter);
    spriteHelicopter.setTextureRect(sf::IntRect(0, 100, 43, 98));
    /*spriteHelicopter.setOrigin(22, 33);*/
    spriteHelicopter.setPosition(PositionXHelicopter, PositionYHelicopter);
    float HelicopterSpeed = 300.f;

    
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
    // Configuration du syst�me de tir
    struct Projectile
    {
        sf::Sprite sprite;
        bool isActive = true;
    };

    std::vector<Projectile> projectiles(30); // Pool de projectiles
    float shootCooldown = 0.25f;
    float timeSinceLastShot = shootCooldown;

    // Initialisation des projectiles
    for (auto& projectile : projectiles)
    {
        projectile.sprite.setTexture(Bullet);
        projectile.sprite.setOrigin(Bullet.getSize().x / 2.f,
            Bullet.getSize().y / 2.f);
        projectile.sprite.setScale(0.5f, 0.5f);
    }


    //Clock for move the draw
    const sf::Clock clock;
    const sf::Clock spawnClock;
    const sf::Time refreshTime = sf::seconds(1.f / 60.f);
    auto startSpawn = spawnClock.getElapsedTime().asMilliseconds();
    auto previous = clock.getElapsedTime().asMilliseconds();
    auto lag = 0.0;

    int counter = 0;
    bool isStopped = false;

    // Clock pour la gestion du temps
    // Clock pour la gestion du temps
    sf::Clock clockBullet;


    while (window.isOpen())
    {
        float deltaTime = clockBullet.restart().asSeconds();
        timeSinceLastShot += deltaTime;
        if (const auto lastSpawnTick = spawnClock.getElapsedTime().asMilliseconds(); lastSpawnTick - startSpawn >= 1000)
        {
            /*if (!isStopped)
                text.setString(std::to_string(++counter));*/

            startSpawn = lastSpawnTick;
        }

        const auto current = clock.getElapsedTime().asMilliseconds();
        const auto elapsed = current - previous;
        previous = current;
        lag += elapsed;
        window.clear();

        //input
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle = angle + 0.01f;

        while (refreshTime.asMilliseconds() > 0.0
            && lag >= refreshTime.asMilliseconds())
        {
         //update
        spriteRotor.setRotation(-AngularVelocity * (angle * 180 / 3.14));


        spriteHelicopterEnnemi.move(2,0);
        
        if (spriteHelicopterEnnemi.getGlobalBounds().intersects(spriteHelicopter.getGlobalBounds()))
        {
            
            Activate = true;
            
        }
        if(!Activate)
            window.draw(spriteHelicopterEnnemi);
           
        


        sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window est un sf::Window

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && spriteHelicopter.getPosition().x > 43)
        {
            // la touche "fl�che gauche" est enfonc�e : on bouge le rectangle
            spriteHelicopter.move(-HelicopterSpeed * deltaTime, 0);
            spriteRotor.move(-HelicopterSpeed * deltaTime, 0);


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && spriteHelicopter.getPosition().x < x - 85)
        {
            // la touche "fl�che droite" est enfonc�e : on bouge le rectangle
            spriteHelicopter.move(HelicopterSpeed * deltaTime, 0);
            spriteRotor.move(HelicopterSpeed * deltaTime, 0);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && spriteHelicopter.getPosition().y > 29)
        {
            // la touche "fl�che haut" est enfonc�e : on bouge le rectangle
            spriteHelicopter.move(0, -HelicopterSpeed * deltaTime);
            spriteRotor.move(0, -HelicopterSpeed * deltaTime);

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && spriteHelicopter.getPosition().y < y - 105)
        {
            // la touche "fl�che bas" est enfonc�e : on bouge le rectangle
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
                        projectile.sprite.setPosition(
                            spriteHelicopter.getPosition().x + 5,
                            spriteHelicopter.getPosition().y + 20
                        );
                    }
                    // Position du deuxi�me projectile (droite)
                    else
                    {
                        projectile.sprite.setPosition(
                            spriteHelicopter.getPosition().x + 40,
                            spriteHelicopter.getPosition().y + 20
                        );
                    }
                    projectilesShot++;

                    // Reset le cooldown apr�s avoir tir� les deux projectiles
                    if (projectilesShot == 2)
                    {
                        timeSinceLastShot = 0;
                        break;
                    }
                }
            }
        }

        // Mise � jour des projectiles
        for (auto& projectile : projectiles)
        {
            if (projectile.isActive)
            {
                // D�placement du projectile
                projectile.sprite.move(0, -400.f * deltaTime);

                // D�sactivation si hors �cran
                if (projectile.sprite.getPosition().y < -50.f)
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
                window.draw(projectile.sprite);
            }
        }
        window.draw(spriteHelicopter);
        window.draw(spriteRotor);
        

        lag -= refreshTime.asMilliseconds();
    }

        window.display();
    }

    return 0;
}
//Pour la detection de collision on utilise un design pattern strategy
// Pour surcharger un operator += le faire dans la fonction membre avec
// friend class
//throw std::runtime_error("Try to remove non existing");
// faire une fonction destroy
//impl�menter les types des objets(ennemi, perso etc...)
//impl�menter un take dammage et initialiser les points de vies
//impl�menter 2 classe EnnemyFireball et PlayerFireball pour r�gler les probl�mes de collisions de l'entit� et la fireball