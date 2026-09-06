#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <raylib.h>
#include <algorithm>

#include "../globals/globals.hpp"
#include "../enums/gamescreen.hpp"
#include "../handlers/asset_handler.hpp"
#include "../transitions/transition.hpp"
#include "../transitions/fade_in.hpp"
#include "../transitions/fade_out.hpp"
#include "../../include/levels/citadel.hpp"
#include "../player/player.hpp"

struct Skip {
	bool draw{ false };
	bool update{ false };
};

class Game
{
public:

	Skip skip;

	void run();

	Camera2D camera{ 0 };
	RenderTexture2D window{ 0 };
	GameScreen screen{ GameScreen::LOADING };
	GameScreen targetScreen{ GameScreen::LOADING };

	std::unique_ptr<Transition> currentTransition{ nullptr };
	TransitionType pendingTransition{ TransitionType::NONE };

	std::unique_ptr<AssetHandler> assets{ nullptr };
	std::unique_ptr<Citadel> citadel{ nullptr };
	std::unique_ptr<Player> player{ nullptr };

	void update(const float &dt);
	void draw();
	void freeResources();
	void drawStatusScreen(const char* status);
	void changeGameScreen(const GameScreen& newScreen);

	void handleTransitions(const float& dt);
	void startTransition(const TransitionType& type);
	void drawTransitions();
};
#endif