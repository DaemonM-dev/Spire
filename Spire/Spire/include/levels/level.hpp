#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <raylib.h>
#include <cmath>
#include <string>
#include <vector>
#include "../globals/globals.hpp"

class Component {

public:
	Component(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos) :
		name(name), texture(texture), size(size), pos(pos) 
	{
		scale = std::fminf((float)texture.width / size.x, (float)texture.width / size.y);
	}
	std::string name;
	const Texture2D& texture;
	Vector2 size;
	Vector2 pos;
	float scale;
};

class Level
{
public:
	std::vector<Component> components;
	void reserveComponentSpace(uint8_t size);
	void addComponent(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos);
	void drawComponent(const std::string& name) const;
	void drawAllComponents() const;
};
#endif