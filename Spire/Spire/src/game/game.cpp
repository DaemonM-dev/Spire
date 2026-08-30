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
		ClearBackground(RAYWHITE);
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
		assetHandler->loadAllAssets();
		if (assetHandler->areAssetsLoaded()) { changeGameScreen(INITIALIZING); }
		break;
	case INITIALIZING:
		changeGameScreen(MAIN_MENU);
		break;
	case MAIN_MENU:
		changeGameScreen(GAMEPLAY);
		break;
	case GAMEPLAY:
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
		break;
	case INITIALIZING:
		break;
	case MAIN_MENU:
		break;
	case GAMEPLAY:
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
