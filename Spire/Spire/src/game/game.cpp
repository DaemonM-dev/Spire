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
	if (skip.update) { skip.update = false; return; }
	handleTransitions(dt);
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
		pendingTransition = FADE_IN;
		changeGameScreen(GAMEPLAY);
		skip.draw = true;
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

	if (skip.draw) { skip.draw = false; return; }

	switch (screen) {
	case LOADING:
		drawStatusScreen("Loading...");
		break;
	case INITIALIZING:
		drawStatusScreen("Initializing...");
		break;
	case MAIN_MENU:
		citadel->draw();
		player->draw();
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

	drawTransitions();
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

void Game::handleTransitions(const float& dt)
{
	if (currentTransition) {
		currentTransition->play(dt);
		if (!currentTransition->isActive()) {
			if(targetScreen != screen){ screen = targetScreen; }
			std::cout << "Changed Game State\n";
			currentTransition.reset();
		}
	} else {
		if (pendingTransition != TransitionType::NONE) {
			startTransition(pendingTransition);
			pendingTransition = TransitionType::NONE;
		}
		if (targetScreen != screen) { screen = targetScreen; std::cout << "Changed Game State\n";
		}
	}
}

void Game::startTransition(const TransitionType& type)
{
	const Vector2ui SIZE = SCREEN_SIZEui;
	const Vector2ui POS = { 0, 0 };
	const float DURATION = 3.0f;

	switch (type) {
	case FADE_IN:
		currentTransition = std::make_unique<FadeIn>(SIZE, POS, DURATION);
		break;
	case FADE_OUT:
		currentTransition = std::make_unique<FadeOut>(SIZE, POS, DURATION);
		break;
	}
}

void Game::drawTransitions()
{
	if (currentTransition) {
		currentTransition->draw();
	}
}

void Game::changeGameScreen(const GameScreen& newScreen)
{
	if (newScreen == targetScreen || newScreen == LOADING) { return; }
	targetScreen = newScreen;
}
