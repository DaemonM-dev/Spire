#include "../game/game.hpp"

void Game::run(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "Spire");
	camera = { { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, 0.0f, 1.0f };
	assets = std::make_unique<AssetHandler>();
	transition = std::make_unique<TransitionHandler>();
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
	transition->handle(dt);
	switch (activeState) {
	case LOADING:
		assets->loadAllAssets();
		if (assets->areAssetsLoaded()) { changeGamestate(INITIALIZING); }
		break;
	case INITIALIZING:
		citadel = std::make_unique<Citadel>();
		citadel->init(assets);
		player = std::make_unique<Player>();
		player->init(assets->getTextureRef("player"));
		changeGamestate(MAIN_MENU);
		break;
	case MAIN_MENU:
		changeGamestate(GAMEPLAY);
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
	handleGamestate();
}

void Game::draw(){
	switch (activeState) {
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
	transition->draw();
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

void Game::handleGamestate()
{
	if (exitingGamestate && transition->isComplete()) {
		exitingGamestate = false;
		activeState = cachedState;
		onStateEnter(activeState);
	}
}

void Game::changeGamestate(const Gamestate& state)
{
	if (state == activeState || state == cachedState || state == LOADING) { return; }
	if (exitingGamestate) { return; }
	if (transition->isActive()) { return; }

	cachedState = state;
	onStateExit(activeState);

	if (transition->isActive()) {
		exitingGamestate = true;
	}
	else {
		activeState = cachedState;
		onStateEnter(activeState);
	}
}

void Game::onStateEnter(const Gamestate& state)
{
	switch (state) {
	case INITIALIZING:
		transition->start(FADE_IN, SCREEN_SIZEui, { 0,0 }, 1.0f);
		break;
	case MAIN_MENU:
		transition->start(FADE_IN, SCREEN_SIZEui, { 0,0 }, 3.0f);
		break;
	case GAMEPLAY:
		// transition->start(FADE_IN, SCREEN_SIZEui, { 0,0 }, 3.0f);
		break;
	default:
		break;
	}
}

void Game::onStateExit(const Gamestate& state)
{
	switch (state) {
	case LOADING:
		transition->start(FADE_OUT, SCREEN_SIZEui, { 0,0 }, 1.0f);
		break;
	case INITIALIZING:
		transition->start(FADE_OUT, SCREEN_SIZEui, { 0,0 }, 1.0f);
		break;
	case MAIN_MENU:
		// transition->start(FADE_OUT, SCREEN_SIZEui, { 0,0 }, 3.0f);
		break;
	case GAMEPLAY:
		//transition->start(FADE_OUT, SCREEN_SIZEui, { 0,0 }, 3.0f);
		break;
	default:
		break; // most states won't need an exit transition
	}
}
