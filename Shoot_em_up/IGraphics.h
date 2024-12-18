#pragma once
#include"IGameObject.h"

class IGraphics 
{
public:
	virtual ~IGraphics() = default;

	 void Render();

};