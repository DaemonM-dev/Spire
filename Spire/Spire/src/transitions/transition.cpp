#include "../../include/game/game.hpp"
#include "../transitions/transition.hpp"
#include "../../include/transitions/fade_in.hpp"
#include "../../include/transitions/fade_out.hpp"

/*
void startTransition(const TransitionType& type, Game& game) {
	bool active = true;
	std::unique_ptr<Transition> activeTransition{ nullptr };
	const Vector2ui SIZE = SCREEN_SIZEui;
	const Vector2ui POS = { 0,0 };
	const float DURATION = 3.0f;
	switch (type) {
	case FADE_IN:
		activeTransition = std::make_unique<FadeIn>(SIZE, POS, DURATION);
		break;
	case FADE_OUT:
		activeTransition = std::make_unique<FadeOut>(SIZE, POS, DURATION);
		break;
	}
	while (active) {
		if (WindowShouldClose()) { game.gameExit = true;; return; }
		float dt = GetFrameTime();
		activeTransition->play(dt);
		game.citadel->update(dt);
		if (!activeTransition->isActive()) {
			activeTransition.reset();
			active = false;
			std::cout << "Ending Transition\n";
			return;
		}
		BeginDrawing();
		BeginMode2D(game.camera);
		ClearBackground(BLACK);
		game.citadel->draw();
		game.player->draw();
		activeTransition->draw();
		EndMode2D();
		EndDrawing();
	}
}
*/