#ifndef CITADEL_HPP
#define CITADEL_HPP
#include "../globals/globals.hpp"
#include "./level.hpp"
#include "../handlers/asset_handler.hpp"
class Citadel : public Level
{
public:
	Citadel(const std::unique_ptr<AssetHandler> &assets);

	void update(const float &dt);
	void draw() const;
private:
	void moveClouds(const float &dt);
};
#endif