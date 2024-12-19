
#include "Game.h"
#include "IGameObject.h"
#include "Player.h"
#include "BattleShip.h"

Game::Game(sf::RenderWindow& window, MilitaryMenu& militaryMenu)
    : m_window(window)
    , m_menu(militaryMenu)
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
//Game::~Game()
//{
//    delete m_collision;
//    for (auto* obj : m_allGameObject) {
//        delete obj;
//    }
//}

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

    m_collision->removeQueuedObjects();
    m_collision->addQueuedObjects();

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


void Game::run() {
    sf::Clock clock;
    bool isPaused = false;

    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                isPaused = !isPaused;
                if (isPaused) {
                    m_menu.openPauseMenu();
                }
                else {
                    m_menu.closePauseMenu();
                }
            }
        }

        if (!isPaused) {
            float deltaTime = clock.restart().asSeconds();
            handleInput();
            update(deltaTime);
            render();
        }
        else {

            m_menu.checkMouseEvent();
            m_menu.draw();


            std::string action = m_menu.getAction();
            if (action == "Resume") {
                isPaused = false;
            }
            else if (action == "Quit") {
                m_window.close();
                break;
            }
        }
    }
}
