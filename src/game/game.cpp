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

    textureMap.emplace("sunset", LoadTexture("./resources/textures/environment/sunset.png"));
    textureMap.emplace("citadel", LoadTexture("./resources/textures/environment/citadel.png"));
    textureMap.emplace("cloud1", LoadTexture("./resources/textures/environment/cloud1.png"));
    textureMap.emplace("cloud2", LoadTexture("./resources/textures/environment/cloud2.png"));
    textureMap.emplace("cloud3", LoadTexture("./resources/textures/environment/cloud3.png"));

    sunset = std::make_unique<TextureComponent>(textureMap["sunset"], gameWindowSize.x, gameWindowSize.y, 0.0f, 0.0f);
    columnPath = std::make_unique<TextureComponent>(textureMap["citadel"], gameWindowSize.x, gameWindowSize.y, 0.0f, 0.0f);

    cloud1_1 = std::make_unique<TextureComponent>(textureMap["cloud1"], gameWindowSize.x, gameWindowSize.y, 0.0f, -30.0f);
    cloud2_1 = std::make_unique<TextureComponent>(textureMap["cloud2"], gameWindowSize.x, gameWindowSize.y, 0.0f, -25.0f);
    cloud3_1 = std::make_unique<TextureComponent>(textureMap["cloud3"], gameWindowSize.x, gameWindowSize.y, 0.0f, -15.0f);

    cloud1_2 = std::make_unique<TextureComponent>(textureMap["cloud1"], gameWindowSize.x, gameWindowSize.y, gameWindowSize.x, -30.0f);
    cloud2_2 = std::make_unique<TextureComponent>(textureMap["cloud2"], gameWindowSize.x, gameWindowSize.y, gameWindowSize.x, -25.0f);
    cloud3_2 = std::make_unique<TextureComponent>(textureMap["cloud3"], gameWindowSize.x, gameWindowSize.y, gameWindowSize.x, -15.0f);
}
void Game::Update(const float& dt){
    // Front
    float speed = 12 * dt;
    cloud1_1->move(-speed, 0);
    cloud1_2->move(-speed, 0);
    if(cloud1_1->xPos < -cloud1_1->width){
        cloud1_1->setPosition(cloud1_2->xPos + cloud1_2->width, cloud1_1->yPos);
    } else if(cloud1_2->xPos < -cloud1_2->width){
        cloud1_2->setPosition(cloud1_1->xPos + cloud1_1->width, cloud1_2->yPos);
    }

    // Middle
    speed = 5 * dt;
    cloud2_1->move(-speed, 0);
    cloud2_2->move(-speed, 0);
    if(cloud2_1->xPos < -cloud2_1->width){
        cloud2_1->setPosition(cloud2_2->xPos + cloud2_2->width, cloud2_1->yPos);
    } else if(cloud2_2->xPos < -cloud2_2->width){
        cloud2_2->setPosition(cloud2_1->xPos + cloud2_1->width, cloud2_2->yPos);
    }

    // Back
    speed = 3 * dt;
    cloud3_1->move(-speed, 0);
    cloud3_2->move(-speed, 0);
    if(cloud3_1->xPos < -cloud3_1->width){
        cloud3_1->setPosition(cloud3_2->xPos + cloud3_2->width, cloud3_1->yPos);
    } else if(cloud3_2->xPos < -cloud3_2->width){
        cloud3_2->setPosition(cloud3_1->xPos + cloud3_1->width, cloud3_2->yPos);
    }

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
        {0.0f, 0.0f, (float)gameWindow.texture.width, -(float)gameWindow.texture.height},
        {gameWindowPos.x, gameWindowPos.y, (gameWindowSize.x * gameScale), (gameWindowSize.y * gameScale)},
        {0.0f,0.0f},
        0.0f,
        RAYWHITE
    );
    EndDrawing();
}
void Game::Draw(){

    sunset->draw();
    cloud3_1->draw(); // Back
    cloud3_2->draw(); 
    cloud2_1->draw(); // Middle
    cloud2_2->draw(); 
    cloud1_1->draw(); // Front
    cloud1_2->draw(); 
    columnPath->draw();

}
void Game::FreeResources(){
    UnloadRenderTexture(gameWindow);

    for (auto it = textureMap.begin(); it != textureMap.end(); ++it) {
        UnloadTexture(it->second);
    }

}