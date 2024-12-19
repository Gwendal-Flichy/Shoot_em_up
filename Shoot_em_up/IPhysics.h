#pragma once
<<<<<<< Updated upstream
=======
#include "IGameObject.h"

class IGameObject;

class IPhysics
{
public:
	virtual ~IPhysics() = default;

	virtual void update(float deltaTime) =0 ;
    

    virtual void checkCollisions() = 0;

    virtual void addObject(IGameObject* object) = 0;

private:
    std::vector<std::unique_ptr<IGameObject>> objects;
    std::vector<size_t> objectsToRemove;
    std::vector<IGameObject*> objectsToAdd;

private:
    virtual bool checkCollision(const IGameObject& obj1, const IGameObject& obj2) = 0;


    virtual void handleCollision(size_t index1, size_t index2) = 0;


    // [Reste du code de GameWorld comme avant...]
    virtual void queueForRemoval(size_t index) = 0;


    virtual void removeQueuedObjects() = 0;


    virtual void addQueuedObjects() = 0;

    

};
>>>>>>> Stashed changes
