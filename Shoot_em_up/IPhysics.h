#pragma once
#include "IGameObject.h"

class IPhysics
{
public:
	~IPhysics() = default;

	void Update();
};
