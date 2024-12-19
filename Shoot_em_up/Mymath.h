#pragma once
#include "IGameObject.h"

struct Vec2
{

    float x;
    float y;
    float getlenght();
    Vec2& operator+=(const Vec2& op1);
    Vec2& operator-=(const Vec2& op1);
};

struct AABB
{
    Vec2 min;
    Vec2 max;

};

std::ostream& operator<<(std::ostream& s, const Vec2& f);


Vec2 operator+(const Vec2& op1, const Vec2& op2);

Vec2 operator-(const Vec2& op1, const Vec2& op2);

Vec2 operator*(const Vec2& op1, const Vec2& op2);

Vec2 operator*(const Vec2& op1, const float& op2);

Vec2 operator*(const float& op1, const Vec2& op2);

Vec2 operator/(const Vec2& op1, const Vec2& op2);


//pour la Vitesse max on peut utiliser un produit scalere car il faut calculer la longueur du vecteur max 
float dotProduct(Vec2& op1, Vec2& op2);


