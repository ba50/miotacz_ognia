#pragma once

#include <memory>

#include "Vec2.h"
#include "Texture.h"

class Block
{
	const int width;
	const int height;

	const Vecf2 position;
	const SDL_Rect clip;
	const std::shared_ptr<Texture> sprite;

	friend class Renderer;

public:
	float temperature;

public:
	Block(const Vecf2 position, const float temperature, const std::string &file_name, const Renderer &ren);

};