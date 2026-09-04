#include "../game/game.hpp"

void Game::run(){
	SetConfigFlags(FLAG_VSYNC_HINT);
	InitWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "Spire");
	camera = { { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, { (float)SCREEN_SIZE.x, (float)SCREEN_SIZE.y }, 0.0f, 1.0f };
	assetHandler = std::make_unique<AssetHandler>();
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

void Game::fadeIn(const float& dt)
{
	if (fadingIn == true && fadeColor.a > 0) {
		fadeColor.a -= 1 * dt;
	}
	else {
		fadeColor.a = 255;
		fadingIn = false;
	}
}

void Game::drawFadeIn()
{
	DrawRectangle(0, 0, SCREEN_SIZE.x, SCREEN_SIZE.y, fadeColor);
}

void Game::update(const float &dt){
	switch (screen) {
	case LOADING:
		assetHandler->loadAllAssets();
		if (assetHandler->areAssetsLoaded()) { changeGameScreen(INITIALIZING); }
		break;
	case INITIALIZING:
		citadel = std::make_unique<Citadel>();
		citadel->init(assetHandler);

		player = std::make_unique<Player>();
		player->init(assetHandler->getTextureRef("player"));
		fadingIn = true;
		changeGameScreen(MAIN_MENU);
		break;
	case MAIN_MENU:
		fadeIn(dt);
		if(fadingIn == false)changeGameScreen(GAMEPLAY);
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
		citadel->draw();
		player->draw();
		drawFadeIn();
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
	assetHandler->unloadAllAssets();
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
#ifndef DEBUG
	std::string oldName;
	switch (screen) {
	case LOADING: oldName = "LOADING"; break;
	case INITIALIZING: oldName = "INITIALIZING"; break;
	case MAIN_MENU: oldName = "MAIN_MENU"; break;
	case GAMEPLAY: oldName = "GAMEPLAY"; break;
	case PAUSE: oldName = "PAUSE"; break;
	case INFO: oldName = "INFO"; break;
	case GAMEOVER: oldName = "GAMEOVER"; break;}
	std::string newName;
	switch (newScreen) {
	case LOADING: newName = "LOADING"; break;
	case INITIALIZING: newName = "INITIALIZING"; break;
	case MAIN_MENU: newName = "MAIN_MENU"; break;
	case GAMEPLAY: newName = "GAMEPLAY"; break;
	case PAUSE: newName = "PAUSE"; break;
	case INFO: newName = "INFO"; break;
	case GAMEOVER: newName = "GAMEOVER"; break;
	}
	std::cout << "\nChanging GameScreen from " << oldName << " to " << newName << "\n";
#endif
	screen = newScreen;
}
