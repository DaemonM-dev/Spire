#include "../../include/levels/level.hpp"

void Level::reserveLayerSpace(uint8_t size) {
	layers.reserve(size);
}

void Level::addLayer(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos){
	layers.emplace_back(name, texture, size, pos);
}

void Level::drawSingleLayer(const std::string& name) const{
	uint8_t index = 0;
	const uint8_t LENGTH{ (uint8_t)layers.size() };
	for (uint8_t i = 0; i < LENGTH; i++) {
		if (name == layers[i].name) {
			index = i;
			break;
		}
	}
	DrawTexturePro(
		layers[index].texture,
		{ 0.0f, 0.0f, (float)layers[index].texture.width, (float)layers[index].texture.height },
		{ layers[index].pos.x, layers[index].pos.y, (float)layers[index].size.x, (float)layers[index].size.y },
		{ 0.0f,0.0f }, 0.0f, RAYWHITE);
}

void Level::drawAllLayers() const{
	const uint8_t LENGTH{ (uint8_t)layers.size() };
	for (uint8_t i = 0; i < LENGTH; i++) {
		DrawTexturePro(
			layers[i].texture,
			{ 0.0f, 0.0f, (float)layers[i].texture.width, (float)layers[i].texture.height },
			{ layers[i].pos.x, layers[i].pos.y, (float)layers[i].size.x, (float)layers[i].size.y },
			{ 0.0f,0.0f }, 0.0f, RAYWHITE);
	}
}
