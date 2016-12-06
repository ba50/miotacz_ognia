#pragma once
#include <string>
#include <memory>

#include "SDL.h"

class Renderer;

class Texture
{
public:
	SDL_Texture *texture;

public:
	Texture(const std::string &file, const Renderer &ren);
	~Texture();
};