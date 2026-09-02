#include "../../include/levels/citadel.hpp"

Citadel::Citadel(const std::unique_ptr<AssetHandler> &assets) {
	this->reserveComponentSpace(8);

	this->addComponent("sunset",	 assets->getTextureRef("sunset"),  SCREEN_SIZE, { 0.0f, 0.0f });
	this->addComponent("cloud3.1",	 assets->getTextureRef("cloud3"),  SCREEN_SIZE, { 0.0f, -35.0f });
	this->addComponent("cloud3.2",	 assets->getTextureRef("cloud3"),  SCREEN_SIZE, { SCREEN_SIZE.x, -35.0f });
	this->addComponent("cloud2.1",	 assets->getTextureRef("cloud2"),  SCREEN_SIZE, { 0.0f, -50.0f });
	this->addComponent("cloud2.2",	 assets->getTextureRef("cloud2"),  SCREEN_SIZE, { SCREEN_SIZE.x, -50.0f });
	this->addComponent("cloud1.1",	 assets->getTextureRef("cloud1"),  SCREEN_SIZE, { 0.0f, -50.0f });
	this->addComponent("cloud1.2",	 assets->getTextureRef("cloud1"),  SCREEN_SIZE, { SCREEN_SIZE.x, -50.0f });
	this->addComponent("background", assets->getTextureRef("citadel"), SCREEN_SIZE, { 0.0f, 0.0f });
}

void Citadel::update(const float& dt) {
	moveClouds(dt);
}

void Citadel::draw() const{
	drawAllComponents();
}

void Citadel::moveClouds(const float& dt){
	float speed = 3 * dt;
	components[1].pos.x -= speed;
	components[2].pos.x -= speed;

	speed = 6 * dt;
	components[3].pos.x -= speed;
	components[4].pos.x -= speed;

	speed = 15 * dt;
	components[5].pos.x -= speed;
	components[6].pos.x -= speed;

	for (int i = 1; i < 7; i++) {
		if (components[i].pos.x < -SCREEN_SIZE.x) {
			components[i].pos.x = SCREEN_SIZE.x;
		}
	}
}
