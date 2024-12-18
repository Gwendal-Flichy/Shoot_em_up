#pragma once
#include "SceneBase.h"
#include <SFML/Graphics.hpp>

class Menu : public SceneBase
{
public:
    Menu(sf::RenderWindow* window, const float& framerate)
        : SceneBase(window, framerate)
    {
        m_shape.setRadius(300.f);
        m_shape.setPointCount(10);
        m_shape.setFillColor(sf::Color::Green);
    }

    void processInput(const sf::Event& event) override
    {

    }

    void update(const float& deltaTime) override
    {

    }

    void render() override
    {
        m_renderWindow->draw(m_shape);
    }

private:
    sf::CircleShape m_shape;
};