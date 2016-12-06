#pragma once

#include "Camera.h"
#include "Define.h"

Camera::Camera(Vecf2 position, float width, float height) :
	position(position),
	toCenter({ width / 2.f, height / 2.f })
{
	Camera::position.y = (position.y - toCenter.y);
	Camera::position.x = (position.x - toCenter.x);
}