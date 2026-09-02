#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <raylib.h>
#include <string>
#include <vector>
#include "../globals/globals.hpp"

class Component {
public:
	Component(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos) :
		name(name), texture(texture), size(size), pos(pos) {
	}
	std::string name;
	const Texture2D& texture;
	Vector2 size;
	Vector2 pos;
};

#endif