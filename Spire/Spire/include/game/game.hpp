#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include <algorithm>

#include "../globals/globals.hpp"
#include "../enums/gamescreen.hpp"
#include "../handlers/asset_handler.hpp"
#include "../../include/levels/citadel.hpp"

class Game
{
public:
	void run();
private:
	Camera2D camera{ 0 };
	RenderTexture2D window{ 0 };
	GameScreen screen{ GameScreen::LOADING };
	std::unique_ptr<AssetHandler> assetHandler{ nullptr };
	std::unique_ptr<Citadel> citadel{ nullptr };
	
	void update(const float &dt);
	void draw();
	void freeResources();
	void changeGameScreen(GameScreen newScreen);

};
#endif