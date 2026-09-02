#include "../../include/levels/level.hpp"

void Level::reserveComponentSpace(uint8_t size) {
	components.reserve(size);
}

void Level::addComponent(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos){
	components.emplace_back(name, texture, size, pos);
}

void Level::drawComponent(const std::string& name) const{
	uint8_t index = 0;
	const uint8_t LENGTH{ (uint8_t)components.size() };
	for (uint8_t i = 0; i < LENGTH; i++) {
		if (name == components[i].name) {
			index = i;
			break;
		}
	}
	DrawTexturePro(
		components[index].texture,
		{ 0.0f, 0.0f, (float)components[index].texture.width, (float)components[index].texture.height },
		{ components[index].pos.x, components[index].pos.y, (float)components[index].size.x, (float)components[index].size.y },
		{ 0.0f,0.0f }, 0.0f, RAYWHITE);
}

void Level::drawAllComponents() const{
	const uint8_t LENGTH{ (uint8_t)components.size() };
	for (uint8_t i = 0; i < LENGTH; i++) {
		DrawTexturePro(
			components[i].texture,
			{ 0.0f, 0.0f, (float)components[i].texture.width, (float)components[i].texture.height },
			{ components[i].pos.x, components[i].pos.y, (float)components[i].size.x, (float)components[i].size.y },
			{ 0.0f,0.0f }, 0.0f, RAYWHITE);
	}
}
