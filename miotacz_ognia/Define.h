#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>

#include <SDL.h>
#include <SDL_image.h>

#define PI 3.1416f

//Screen attributes
#define BASE_WIDTH 640
#define BASE_HEIGHT 480

//Screen attributes
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define BLOCK_SIZE 32

namespace Error
{
	/*
	* Log an SDL error with some error message to the output stream of our choice
	* @param os The output stream to write the message too
	* @param msg The error message to write, format will be msg error: SDL_GetError()
	*/
	static void LogSDL(std::ostream &os, const std::string &msg)
	{
		os << msg << " error: " << SDL_GetError() << std::endl;
		throw std::exception("shit!");
	}
}

namespace Math {
	template <typename T> int Sgn(T val) {
		return (T(0) < val) - (val < T(0));
	}

	inline float Rand(float start, float stop) {
		return start + static_cast<float>(((stop - start)*rand()) / (RAND_MAX + 1.0));
	}
}

namespace Gameplaye {
	static float deltaTime = 1e-2f;

}