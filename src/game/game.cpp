#include "game.hpp"

void Game::Run(){

    gameWindowSize = {960.0f, 540.0f};

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);
    InitWindow(gameWindowSize.x, gameWindowSize.y, "Spire");
    SetWindowMinSize(gameWindowSize.x, gameWindowSize.y);
    MaximizeWindow();

    int monitor = GetCurrentMonitor();
    screenSize = {(float)GetMonitorWidth(monitor), (float)GetMonitorHeight(monitor)};
    gameWindow = LoadRenderTexture(gameWindowSize.x, gameWindowSize.y);
    gameScale = std::min((screenSize.x / gameWindowSize.x), (screenSize.y / gameWindowSize.y));

    gameWindowPos = {
        (screenSize.x - (gameWindowSize.x * gameScale)) * 0.5f,
        (screenSize.y - (gameWindowSize.y * gameScale)) * 0.5f
    };

    Initialize();
    while(!WindowShouldClose()){
        const float deltaTime = GetFrameTime();
        Update(deltaTime);
        UpdateRenderWindow();
        DrawRenderWindow();
    }
    FreeResources();
    CloseWindow();
}
void Game::Initialize(){
    background = LoadTexture("./resources/textures/environment/citadel.png");
}
void Game::Update(const float& dt){
    if(dt){return;}
}
void Game::UpdateRenderWindow(){
    const Vector2 newScreenSize = {(float)GetScreenWidth(), (float)GetScreenHeight()};
    if(newScreenSize.x != screenSize.x || newScreenSize.y != screenSize.y){
        screenSize = newScreenSize;
        gameScale = std::min((screenSize.x / gameWindowSize.x), (screenSize.y / gameWindowSize.y));
        gameWindowPos = {
            (screenSize.x - (gameWindowSize.x * gameScale)) * 0.5f,
            (screenSize.y - (gameWindowSize.y * gameScale)) * 0.5f
        };
    }
}
void Game::DrawRenderWindow(){
    BeginTextureMode(gameWindow);
    ClearBackground(BLACK);
    Draw();
    EndTextureMode();
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(
        gameWindow.texture,
        {0.0f, 0.0f, (float)gameWindow.texture.width, -(float)gameWindow.texture.height}, // src
        {gameWindowPos.x, gameWindowPos.y, (gameWindowSize.x * gameScale), (gameWindowSize.y * gameScale)}, // dest
        {0.0f,0.0f}, // origin
        0.0f, // rotation
        RAYWHITE // tint
    );
    EndDrawing();
}
void Game::Draw(){
    DrawTexturePro(background,
        {0.0f, 0.0f, (float)background.width, (float)background.height},
        {0.0f, 0.0f, gameWindowSize.x, gameWindowSize.y},
        {0.0f, 0.0f},
        0.0f,
        RAYWHITE
        );
}
void Game::FreeResources(){
    UnloadRenderTexture(gameWindow);
    UnloadTexture(background);
}