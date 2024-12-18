#pragma once
#include "IGameObject.h"
#include "cmath"

std::ostream& operator<<(std::ostream& s, const Vec2& f)
{
    s << f.x << " / " << f.y;
    return s;
}

Vec2 operator+(const Vec2& op1, const Vec2& op2)
{
    Vec2 tmp{ op1.x + op2.x , op1.y + op2.y};
    return tmp;
}
Vec2 operator-(const Vec2& op1, const Vec2& op2)
{
    Vec2 tmp{ op1.x - op2.x , op1.y - op2.y };
    return tmp;
}
Vec2 operator*(const Vec2& op1, const Vec2& op2)
{
    Vec2 tmp{ op1.x * op2.x , op1.y * op2.y };
    return tmp;
}
Vec2 operator*(const Vec2& op1, const float& op2)
{
    Vec2 tmp{ op1.x * op2 , op1.y * op2 };
    return tmp;
}
Vec2 operator*(const float& op1, const Vec2& op2)
{
    Vec2 tmp{ op2.x * op1 , op2.y * op1 };
    return tmp;
}
Vec2 operator/(const Vec2& op1, const Vec2& op2)
{
    Vec2 tmp{ op1.x / op2.x, op1.y / op2.y };
    return tmp;
}

//pour la Vitesse max on peut utiliser un produit scalere car il faut calculer la longueur du vecteur max 
float dotProduct(Vec2& op1, Vec2& op2)
{
    return op1.x * op2.x + op1.y * op2.y;
}

float Vec2::getlenght()
{
    return std::sqrt(dotProduct(*this, *this));
}

Vec2& Vec2::operator+=(const Vec2& op1)
{
    x += op1.x;
    y += op1.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& op1)
{
    x -= op1.x;
    y -= op1.y;
    return *this;
}