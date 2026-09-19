#include "game.hpp"

void Game::Run(){
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(960, 540, "Spire");
    Initialize();
    while(!WindowShouldClose()){
        const float deltaTime = GetFrameTime();
        Update(deltaTime);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Draw();
        EndDrawing();
    }
    FreeResources();
    CloseWindow();
}
void Game::Initialize(){
    
}
void Game::Update(const float& dt){

}
void Game::Draw(){

}
void Game::FreeResources(){

}