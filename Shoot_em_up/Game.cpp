#include "Game.h"
#include "IGameObject.h"
#include "Player.h"
Game::Game() : m_window(sf::VideoMode(800, 800), "SFML works!")
{
    m_window.setFramerateLimit(60);
    
    
    m_allGameObject.push_back(new PlayerShip(*this));

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
    for (auto& GameObject : m_allGameObject)
    {
        GameObject->update(deltaTime);
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