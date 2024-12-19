#include "Collision.h"

Collision::Collision(Game& gameRef)
    :gameRef(gameRef)
{}
void Collision::update(float deltaTime)
{
    checkCollisions();

    

    /*removeQueuedObjects();
    addQueuedObjects();*/
}
void Collision::checkCollisions()
{
    for (size_t i = 0; i < objects.size(); ++i)
    {
        for (size_t j = i + 1; j < objects.size(); ++j)
        {
            if (checkCollision(*objects[i], *objects[j]))
            {
                handleCollision(i, j);
            }
        }
    }
}
bool Collision::checkCollision(const IGameObject& obj1, const IGameObject& obj2)
{
    return obj1.getBounds().intersects(obj2.getBounds());
}
void Collision:: handleCollision(size_t index1, size_t index2)
{
    ObjectType type1 = objects[index1]->getObjectType();
    ObjectType type2 = objects[index2]->getObjectType();

    // Gérer les différents cas de collision
    if (type1 == ObjectType::Player && type2 == ObjectType::Enemy)
    {
        // Collision vaisseau-ennemi
        queueForRemoval(index2); // Supprime l'ennemi
        gameRef.removeGameObject(objects[index2].get());
        // Gérer les dégâts au vaisseau...
    }
    else if (type1 == ObjectType::ProjectileP && type2 == ObjectType::Enemy)
    {
        // Collision projectile-ennemi
        queueForRemoval(index1); // Supprime le projectile
        queueForRemoval(index2); // Supprime l'ennemi
        gameRef.removeGameObject(objects[index1].get());
        gameRef.removeGameObject(objects[index2].get());
    }
    else if (type1 == ObjectType::Player && type2 == ObjectType::ProjectileE)
    {
        // Collision vaisseau-astéroïde
        queueForRemoval(index2); // Supprime l'astéroïde
        gameRef.removeGameObject(objects[index2].get());
        // Gérer les dégâts au vaisseau...
    }
    // Ajoutez d'autres cas selon vos besoins...

    // Inverser l'ordre si nécessaire
    if (type2 < type1)
    {
        handleCollision(index2, index1);
        return;
    }
}
void Collision:: queueForRemoval(size_t index)
{
    objectsToRemove.push_back(index);
}
void Collision:: removeQueuedObjects()
{
    std::sort(objectsToRemove.begin(), objectsToRemove.end(), std::greater<size_t>());
    for (size_t index : objectsToRemove)
    {
        if (index < objects.size())
        {
            objects.erase(objects.begin() + index);
        }
    }
    objectsToRemove.clear();
}
void Collision:: addQueuedObjects()
{
    for (auto* obj : objectsToAdd)
    {
        objects.push_back(std::unique_ptr<IGameObject>(obj));
    }
    objectsToAdd.clear();
}
void Collision:: addObject(IGameObject* object)
{
    objectsToAdd.push_back(object);
}