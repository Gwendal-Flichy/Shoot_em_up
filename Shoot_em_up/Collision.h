#pragma once
#include "IPhysics.h"

class Game;

class Collision : public IPhysics
{
public:
    
	Collision(Game& gameRef);
	/*void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;*/
    void update(float deltaTime) override;


    void checkCollisions() override;

    void addObject(IGameObject* object)override;

private:
    Game& gameRef;
private:
	std::vector<std::unique_ptr<IGameObject>> objects;
	std::vector<size_t> objectsToRemove;
	std::vector<IGameObject*> objectsToAdd;

private:
    bool checkCollision(const IGameObject& obj1, const IGameObject& obj2) override;
    

    void handleCollision(size_t index1, size_t index2) override;
    

    // [Reste du code de GameWorld comme avant...]
    void queueForRemoval(size_t index) override;
    

    void removeQueuedObjects() override;
    

    void addQueuedObjects() override;

    
    
};

