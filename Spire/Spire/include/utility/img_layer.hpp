#ifndef IMG_LAYER_HPP
#define IMG_LAYER_HPP

#include <raylib.h>
#include <string>
#include <vector>
#include "../globals/globals.hpp"

class ImgLayer {
public:
	ImgLayer(std::string name, const Texture2D& texture, Vector2 size, Vector2 pos) :
		name(name), texture(texture), size(size), pos(pos) {}
	std::string name;
	const Texture2D& texture;
	Vector2 size;
	Vector2 pos;
};

#endif