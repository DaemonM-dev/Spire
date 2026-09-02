#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <raylib.h>
#include <string>
#include <vector>
#include "../globals/globals.hpp"
#include "../utility/component.hpp"

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