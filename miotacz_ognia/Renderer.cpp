#include "Renderer.h"

#include "Define.h"
#include "Texture.h"
#include "Camera.h"
#include "Block.h"

#include "cleanup.h"

Renderer::Renderer()
{
	//	Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		Error::LogSDL(std::cout, "SDL_Init_Video");
	}

	//	Setup our window and renderer
	win = SDL_CreateWindow("Game 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		Error::LogSDL(std::cout, "CreateWindow");
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		Error::LogSDL(std::cout, "CreateRenderer");
	}

	camera = std::make_shared<Camera>(Vecf2{ 0.f,0.f }, static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT));
}

Renderer::~Renderer()
{
	cleanup(win, ren);
}

void Renderer::Clear()
{
	SDL_RenderClear(ren);
}

void Renderer::RenderPresent()
{
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	SDL_RenderPresent(ren);
}

void Renderer::Render(Block &block, Vecf2 scale)
{
	SDL_Rect dst;
	dst.x = static_cast<int>(((block.position.x - block.width / 2.f) - camera->position.x) / scale.x);
	dst.y = static_cast<int>(((-block.position.y - block.height / 2.f) - camera->position.y) / scale.y);
	dst.w = static_cast<int>(block.width);
	dst.h = static_cast<int>(block.height);

	SDL_RenderSetScale(ren, scale.x, scale.y);
	SDL_SetTextureBlendMode(block.sprite->texture, SDL_BLENDMODE_BLEND);

	SDL_RenderCopy(ren, block.sprite->texture, &block.clip, &dst);
}