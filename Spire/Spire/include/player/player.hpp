#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "../globals/globals.hpp"
#include "../handlers/asset_handler.hpp"
class Player
{
public:
	Player(const std::unique_ptr<AssetHandler>& assets);

	void draw();

	const Texture2D& spritesheet;
	Vector2 size{240.0f, 240.0f};
	Vector2 pos{SCREEN_SIZE.x / 2 - size.x / 2, SCREEN_SIZE.y - size.y - 100};
};
#endif