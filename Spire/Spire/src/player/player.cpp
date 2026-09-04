#include "../../include/player/player.hpp"

void Player::init(const Texture2D &texture)
{
	spritesheet = std::make_unique<ImgLayer>("PlayerSprite", texture,
		Vector2{ (float)texture.width, (float)texture.height },
		Vector2{ 0.0f, 0.0f });
}

void Player::draw() {
	DrawTexturePro(
		spritesheet->texture,
		{ 0,0,64.0f,64.0f },
		{ pos.x, pos.y, size.x, size.y },
		{ 0.0f,0.0f },
		0.0f, RAYWHITE);
}