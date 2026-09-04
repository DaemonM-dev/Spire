#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <raylib.h>
#include <string>
#include <vector>
#include "../globals/globals.hpp"
#include "../utility/img_layer.hpp"

class Level
{
public:
	std::vector<ImgLayer> layers;
	void reserveLayerSpace(uint8_t size);
	void addLayer(const std::string name, const Texture2D& texture, const Vector2 size, const Vector2 pos);
	void drawSingleLayer(const std::string& name) const;
	void drawAllLayers() const;
};
#endif