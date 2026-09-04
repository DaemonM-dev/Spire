#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include <algorithm>

#include "../globals/globals.hpp"
#include "../enums/gamescreen.hpp"
#include "../handlers/asset_handler.hpp"
#include "../../include/levels/citadel.hpp"
#include "../player/player.hpp"

class Game
{
public:
	void run();
private:
	Camera2D camera{ 0 };
	RenderTexture2D window{ 0 };
	GameScreen screen{ GameScreen::LOADING };
	bool fadingIn = false;
	Color fadeColor{ 0,0,0,255 };
	std::unique_ptr<AssetHandler> assetHandler{ nullptr };
	std::unique_ptr<Citadel> citadel{ nullptr };
	std::unique_ptr<Player> player{ nullptr };

	void fadeIn(const float& dt);
	void drawFadeIn();
	void update(const float &dt);
	void draw();
	void freeResources();
	void drawStatusScreen(const char* status);
	void changeGameScreen(GameScreen newScreen);

};
#endif