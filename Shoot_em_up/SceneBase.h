#pragma once

class SceneBase
{
public:
    SceneBase(sf::RenderWindow* window, const float& framerate)
        : m_renderWindow(window)
        , m_refreshTime(sf::seconds(1.f / framerate))
    {

    }

    virtual ~SceneBase() = default;
    virtual void processInput(const sf::Event& event) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render() = 0;

    sf::Time getRefreshTime() const
    {
        return m_refreshTime;
    }

protected:
    sf::RenderWindow* m_renderWindow;
    sf::Time m_refreshTime;
};