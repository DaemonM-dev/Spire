#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include <algorithm>

#include "../globals/globals.hpp"
#include "../enums/gamestate.hpp"
#include "../handlers/asset_handler.hpp"
#include "../handlers/transition_handler.hpp"
#include "../../include/levels/citadel.hpp"
#include "../player/player.hpp"

class Game
{
public:

	void run();

	Camera2D camera{ 0 };
	RenderTexture2D window{ 0 };

	Gamestate activeState{ Gamestate::LOADING };
	Gamestate cachedState{ Gamestate::LOADING };

	std::unique_ptr<AssetHandler> assets{ nullptr };
	std::unique_ptr<TransitionHandler> transition{ nullptr };
	std::unique_ptr<Citadel> citadel{ nullptr };
	std::unique_ptr<Player> player{ nullptr };

	void update(const float &dt);
	void draw();
	void freeResources();
	void drawStatusScreen(const char* status);

	bool exitingGamestate{ false };
	void handleGamestate();
	void changeGamestate(const Gamestate& state);
	void onStateEnter(const Gamestate& state);
	void onStateExit(const Gamestate& state);
};
#endif