#pragma once


#include "vector"
#include <SFML/Graphics.hpp>
#include "RessourceManager.h"
#include "Collision.h"
#include "MilitaryMenu.h"

class IGameObject;

class Game
{
    friend class Collision;
public:
    
    Game(sf::RenderWindow& window, MilitaryMenu& militaryMenu);
    //~Game();

    void handleInput();

    void update(float deltaTime);

    void render();

    void run();

    TextureCash& getTextureCash();

    void addGameObject(IGameObject* object);

    void removeGameObject(IGameObject* object);
    

private:
    
    std::vector<IGameObject*> m_allGameObject;
    TextureCash m_allTextureCash;
    sf::RenderWindow& m_window;
    MilitaryMenu& m_menu;
    Collision* m_collision;
};

