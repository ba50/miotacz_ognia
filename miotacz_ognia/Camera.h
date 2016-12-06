#pragma once

#include "Vec2.h"

class Character;

class Camera
{
public:
	Vecf2 position;
	Vecf2 toCenter;

public:
	Camera(Vecf2 position, float width, float height);
};
