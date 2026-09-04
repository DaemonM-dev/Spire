#include "../../include/levels/citadel.hpp"

void Citadel::init(const std::unique_ptr<AssetHandler>& assets) {
	this->reserveLayerSpace(8);

	this->addLayer("sunset", assets->getTextureRef("sunset"), SCREEN_SIZE, { 0.0f, 0.0f });
	this->addLayer("cloud3.1", assets->getTextureRef("cloud3"), SCREEN_SIZE, { 0.0f, -35.0f });
	this->addLayer("cloud3.2", assets->getTextureRef("cloud3"), SCREEN_SIZE, { SCREEN_SIZE.x, -35.0f });
	this->addLayer("cloud2.1", assets->getTextureRef("cloud2"), SCREEN_SIZE, { 0.0f, -50.0f });
	this->addLayer("cloud2.2", assets->getTextureRef("cloud2"), SCREEN_SIZE, { SCREEN_SIZE.x, -50.0f });
	this->addLayer("cloud1.1", assets->getTextureRef("cloud1"), SCREEN_SIZE, { 0.0f, -50.0f });
	this->addLayer("cloud1.2", assets->getTextureRef("cloud1"), SCREEN_SIZE, { SCREEN_SIZE.x, -50.0f });
	this->addLayer("background", assets->getTextureRef("citadel"), SCREEN_SIZE, { 0.0f, 0.0f });
}

void Citadel::update(const float& dt) {
	moveClouds(dt);
}

void Citadel::draw() const{
	drawAllLayers();
}

void Citadel::moveClouds(const float& dt){
	float speed = 3 * dt;
	layers[1].pos.x -= speed;
	layers[2].pos.x -= speed;

	speed = 6 * dt;
	layers[3].pos.x -= speed;
	layers[4].pos.x -= speed;

	speed = 15 * dt;
	layers[5].pos.x -= speed;
	layers[6].pos.x -= speed;

	for (int i = 1; i < 7; i++) {
		if (layers[i].pos.x < -SCREEN_SIZE.x) {
			layers[i].pos.x = SCREEN_SIZE.x;
		}
	}
}
