#include "../game/game.hpp"

void Game::run(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "Spire");
	camera = { { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, 0.0f, 1.0f };
	assets = std::make_unique<AssetHandler>();
	while (!WindowShouldClose()){
		float deltaTime = GetFrameTime();
		update(deltaTime);
		BeginDrawing();
		ClearBackground(BLACK);
		BeginMode2D(camera);
		draw();
		EndMode2D();
		EndDrawing();
	}
	freeResources();
	CloseWindow();
}


void Game::update(const float &dt){
	switch (screen) {
	case LOADING:
		assets->loadAllAssets();
		if (assets->areAssetsLoaded()) { changeGameScreen(INITIALIZING); }
		break;
	case INITIALIZING:
		citadel = std::make_unique<Citadel>();
		citadel->init(assets);
		player = std::make_unique<Player>();
		player->init(assets->getTextureRef("player"));
		changeGameScreen(MAIN_MENU);
		break;
	case MAIN_MENU:
		startTransition(FADE_IN, *this);
		changeGameScreen(GAMEPLAY);
		break;
	case GAMEPLAY:
		citadel->update(dt);
		break;
	case PAUSE:
		break;
	case INFO:
		break;
	case GAMEOVER:
		break;
	}
}

void Game::draw(){
	switch (screen) {
	case LOADING:
		drawStatusScreen("Loading...");
		break;
	case INITIALIZING:
		drawStatusScreen("Initializing...");
		break;
	case MAIN_MENU:
		if (playingTransition) {
		citadel->draw();
		player->draw();
	}
		break;
	case GAMEPLAY:
		citadel->draw();
		player->draw();
		break;
	case PAUSE:
		break;
	case INFO:
		break;
	case GAMEOVER:
		break;
	}
}
void Game::freeResources(){
	UnloadRenderTexture(window);
	assets->unloadAllAssets();
}

void Game::drawStatusScreen(const char* status)
{
	uint16_t screenWidth = GetScreenWidth();
	uint16_t screenHeight = GetScreenHeight();
	Vector2 textSize = MeasureTextEx(GetFontDefault(), status, 60, 2);
	Vector2 textPosition = {
		screenWidth / 2.0f - textSize.x / 2.0f,
		screenHeight / 2.0f - textSize.y / 2.0f
	};
	DrawTextEx(GetFontDefault(), status, textPosition, 60, 2, WHITE);
}

void Game::changeGameScreen(GameScreen newScreen)
{
	if (newScreen == screen || newScreen == LOADING) { return; }
	screen = newScreen;
}

void startTransition(const TransitionType& type, const Game& game) {
	std::cout << "Starting Transition\n";
	bool active = true;

	std::unique_ptr<Transition> activeTransition{ nullptr };
	const Vector2ui SIZE = { (uint16_t)SCREEN_SIZE.x, (uint16_t)SCREEN_SIZE.y };
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
		ClearBackground(BLACK);
		game.citadel->draw();
		game.player->draw();
		activeTransition->draw();
		EndDrawing();
	}
}
