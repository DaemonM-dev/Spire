#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <memory>

#include "../globals/globals.hpp"
#include "../utility/img_layer.hpp"
class Player
{
public:

	void init(const Texture2D& texture);
	void draw();
	std::unique_ptr<ImgLayer> spritesheet{ nullptr };
	Vector2 size{240.0f, 240.0f};
	Vector2 pos{SCREEN_SIZE.x / 2 - size.x / 2, SCREEN_SIZE.y - size.y - 100};
};
#endif