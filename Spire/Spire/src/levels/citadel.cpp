#include "../../include/levels/citadel.hpp"

Citadel::Citadel(AssetHandler& assets) {
	this->reserveComponentSpace(8);

	this->addComponent("sunset", assets.getTexture("sunset"), { 0.0f,0.0f });
	this->addComponent("cloud3.1", assets.getTexture("cloud3"), { 0.0f, -10.0f });
	this->addComponent("cloud3.2", assets.getTexture("cloud3"), { (float)SCREEN_SIZE.x, -10.0f });
	this->addComponent("cloud2.1", assets.getTexture("cloud2"), { 0.0f, -20.0f });
	this->addComponent("cloud2.2", assets.getTexture("cloud2"), { (float)SCREEN_SIZE.x, -20.0f });
	this->addComponent("cloud1.1", assets.getTexture("cloud1"), { 0.0f, -20.0f });
	this->addComponent("cloud1.2", assets.getTexture("cloud1"), { (float)SCREEN_SIZE.x, -20.0f });
	this->addComponent("background", assets.getTexture("citadel"), { 0.0f, 0.0f });
}

void Citadel::update(const float& dt) {
	moveClouds(dt);
}

void Citadel::draw(){
	//DrawRectangleGradientV(0, 0, SCREEN_SIZE.x, SCREEN_SIZE.y, RED, YELLOW);
	const int LENGTH = components.size();
	for (int i = 0; i < LENGTH; i++) {
		//if (i == 6) { continue; }
		DrawTexture(components[i].texture, components[i].pos.x, components[i].pos.y, WHITE);
	}
}

void Citadel::moveClouds(const float& dt){
	float speed = 2 * dt;
	components[1].pos.x -= speed;
	components[2].pos.x -= speed;

	speed = 4 * dt;
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
