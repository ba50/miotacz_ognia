#include <memory>

#include "Define.h"
#include "Renderer.h"
#include "Audio.h"
#include "Inputs.h"

#include "Block.h"


int main(int, char**) {

	Vecf2 scale = Vecf2{ static_cast<float>(SCREEN_WIDTH) / static_cast<float>(BASE_WIDTH), static_cast<float>(SCREEN_HEIGHT) / static_cast<float>(BASE_HEIGHT) };
	auto renderer = std::make_unique<Renderer>();
	auto audio = std::make_unique<Audio>();

	std::vector<std::shared_ptr<Block>> block_vector;

	for (float x = -BASE_WIDTH*scale.x; x < BASE_WIDTH*scale.x; x += BLOCK_SIZE*scale.x) {
		block_vector.push_back(std::make_shared<Block>(Vecf2{ x, 0.f }, 0.f, "Source/Block.png", *renderer));
	}



	bool quit = false;
	while (!quit) {
		quit = Inputs::Update();

		renderer->Clear();

		for (auto& block : block_vector) {
			renderer->Render(*block, scale);
		}

		//Update the screen
		renderer->RenderPresent();
	}


	IMG_Quit();
	SDL_Quit();

	system("pause");

	return 0;
}