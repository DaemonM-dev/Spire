#include "../../include/levels/level.hpp"

void Level::reserveComponentSpace(uint8_t size) {
	components.reserve(size);
}

void Level::addComponent(std::string name, const Texture2D& texture, Vector2 size, Vector2 pos){
	components.emplace_back(name, texture, size, pos);
}

void Level::drawComponent(std::string name){
	uint8_t index = 0;
	const uint8_t LENGTH = components.size();

	for (uint8_t i = 0; i < LENGTH; i++) {
		if (name == components[i].name) {
			index = i;
			break;
		}
	}
	DrawTextureV(components[index].texture, components[index].pos, WHITE);
}

void Level::draw(){
	const uint8_t LENGTH = components.size();
	for (uint8_t i = 0; i < LENGTH; i++) {
		DrawTextureV(components[i].texture, components[i].pos, WHITE);
	}
}
