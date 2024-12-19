#include "FireMode.h"
#include "Projectile.h"
#include "Game.h"

void FireMode::basicFire(Game& gameRef, const std::string& texturePath,
    const ObjectType& Type, const Vec2& originPosition, float angle)
{
    // FireMode a accès à addGameObject car c'est une classe amie
    gameRef.addGameObject(new Projectile(gameRef, texturePath, Type,
        originPosition, angle, { 30, 30 }, 1, 50));
}