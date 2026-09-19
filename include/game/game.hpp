#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <raylib.h>

class Game{
    public:

    void Run();

    private:

    RenderTexture2D gameWindow;
    Vector2 gameWindowSize;
    Vector2 gameWindowPos;
    Vector2 screenSize;
    float gameScale;

    Texture2D background;

    void Initialize();
    void Update(const float& dt);
    void UpdateRenderWindow();
    void DrawRenderWindow();
    void Draw();
    void FreeResources();
};

#endif