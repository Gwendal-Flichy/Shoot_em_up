#pragma once

#include "Mymath.h"


class Game;

class FireMode {
public:

    static void basicFire(Game& gameRef, const std::string& texturePath,
        const ObjectType& Type, const Vec2& originPosition={0,0}, float angle = 0);

};