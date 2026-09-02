#include "../../include/player/player.hpp"

Player::Player(const std::unique_ptr<AssetHandler>& assets) : spritesheet(assets->getTextureRef("player")) {}

void Player::draw() {
	DrawTexturePro(
		spritesheet,
		{ 0,0,64.0f,64.0f },
		{ pos.x, pos.y, size.x, size.y },
		{ 0.0f,0.0f },
		0.0f, RAYWHITE);
}