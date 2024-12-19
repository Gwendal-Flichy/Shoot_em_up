#pragma once
<<<<<<< Updated upstream
=======

#include "vector"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "Collision.h"

class IGameObject;

class Game
{
    friend class Collision;
public:
    
    Game();
    ~Game();

    void handleInput();

    void update(float deltaTime);

    void render();

    void run();

    TextureCash& getTextureCash();

    void addGameObject(IGameObject* object);

    void removeGameObject(IGameObject* object);
    

private:
    sf::RenderWindow m_window;
    std::vector<IGameObject*> m_allGameObject;
    TextureCash m_allTextureCash;

    Collision* m_collision;
};
>>>>>>> Stashed changes
