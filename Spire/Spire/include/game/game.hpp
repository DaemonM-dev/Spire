#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include <algorithm>

#include "../globals/globals.hpp"
#include "../enums/gamescreen.hpp"
#include "../handlers/asset_handler.hpp"
#include "../handlers/transition_handler.hpp"
#include "../transitions/fade_in.hpp"
#include "../transitions/fade_out.hpp"
#include "../../include/levels/citadel.hpp"
#include "../player/player.hpp"

enum TransitionType {
	FADE_IN,
	FADE_OUT
};

class Game
{
public:
	bool gameExit = false;
	void run();

	Camera2D camera{ 0 };
	RenderTexture2D window{ 0 };
	GameScreen screen{ GameScreen::LOADING };
	bool playingTransition = false;
	std::unique_ptr<AssetHandler> assets{ nullptr };
	std::unique_ptr<Citadel> citadel{ nullptr };
	std::unique_ptr<Player> player{ nullptr };

	void exitGame();
	void update(const float &dt);
	void draw();
	void freeResources();
	void drawStatusScreen(const char* status);
	void changeGameScreen(GameScreen newScreen);
};

void startTransition(const TransitionType& type, Game& game);

#endif