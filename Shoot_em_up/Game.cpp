<<<<<<< Updated upstream
=======
#include "Game.h"
#include "IGameObject.h"
#include "Player.h"
#include "BattleShip.h"

Game::Game() 
    : m_window(sf::VideoMode(800, 800), "SFML works!")
    
{
    m_window.setFramerateLimit(60);
    
    m_collision = new Collision(*this);
    
    auto player = new PlayerShip(*this);
    auto battleship = new Battleship(*this);

    m_allGameObject.push_back(player);
    m_allGameObject.push_back(battleship);

    m_collision->addObject(player);
    m_collision->addObject(battleship);
}
Game::~Game()
{
    delete m_collision;
    for (auto* obj : m_allGameObject) {
        delete obj;
    }
}

void Game::handleInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
    for (auto& GameObject : m_allGameObject)
    {
        GameObject->handleInput();
    }
}


void Game::update(float deltaTime)
{
    m_collision->update(deltaTime);
    for (auto& GameObject : m_allGameObject)
    {
        GameObject->update(deltaTime);
    }
}

void Game:: addGameObject(IGameObject* object)
{
    m_allGameObject.push_back(object);
    m_collision->addObject(object);
}

void Game:: removeGameObject(IGameObject* object)
{
    auto it = std::find(m_allGameObject.begin(), m_allGameObject.end(), object);
    if (it != m_allGameObject.end())
    {
        m_allGameObject.erase(it);
    }
}

void Game::render()
{

    m_window.clear();
    for (auto& GameObject : m_allGameObject)
    {
        GameObject->render(m_window);
    }
    m_window.display();
}



TextureCash& Game::getTextureCash()
{
    return m_allTextureCash;
}


void Game::run()
{
    
    //auto lastTime = getCurrentTime();
    while (true)
    {
        //const auto currentTime = getCurrentTime();
        //const auto elapsedTime = currentTime - lastTime;

        handleInput();
        update(1.f/60.f);
        render();

        //lastTime = currentTime;
    }
}
>>>>>>> Stashed changes
