#pragma once
#define GAME_H

#include "vector"
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
#include "MilitaryMenu.h"
class IGameObject;
class  MilitaryMenu;

class Game
{
    friend class PlayerShip;
public:
    
    
    Game(sf::RenderWindow& window, MilitaryMenu& militaryMenu);
    void handleInput();

    void update(float deltaTime);

    void render();

    void run();

    TextureCash& getTextureCash();


    

   

private:
    sf::RenderWindow& m_window; 
    std::vector<IGameObject*> m_allGameObject;
    TextureCash m_allTextureCash;
    MilitaryMenu& m_menu;
};