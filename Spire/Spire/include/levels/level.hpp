#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <raylib.h>
#include <string>
#include <vector>
#include "../globals/globals.hpp"

class Image2D {

public:
	Image2D(std::string name, const Texture2D& texture, Vector2 pos) : 
		name(name), texture(texture), pos(pos) {
	}
	std::string name;
	const Texture2D& texture;
	Vector2 pos;
};

class Level
{
public:
	std::vector<Image2D> components;

	void reserveComponentSpace(uint8_t size);
	void addComponent(std::string name, const Texture2D& texture, Vector2 pos);
	void drawComponent(std::string name);
	virtual void update(const float& dt) {};
	virtual void draw();
};
#endif