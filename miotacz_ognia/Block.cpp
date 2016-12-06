#include "Block.h"

#include "Define.h"
#include "Renderer.h"

Block::Block(const Vecf2 position,const float temperature, const std::string &file_name, const Renderer &ren)
	: 
	position(position), 
	width(BLOCK_SIZE), 
	height(BLOCK_SIZE),
	temperature(temperature), 
	clip{ 0, 0,BLOCK_SIZE,BLOCK_SIZE},
	sprite{ std::make_shared<Texture>(file_name, ren) }
{}
