#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <raylib.h>
#include "component.hpp"

class Game{
    public:

    void Run();

    private:

    RenderTexture2D gameWindow;
    Vector2 gameWindowSize;
    Vector2 gameWindowPos;
    Vector2 screenSize;
    float gameScale;

    std::map<std::string, Texture2D> textureMap;

    std::unique_ptr<TextureComponent> sunset{nullptr};
    std::unique_ptr<TextureComponent> columnPath{nullptr};

    void Initialize();
    void Update(const float& dt);
    void UpdateRenderWindow();
    void DrawRenderWindow();
    void Draw();
    void FreeResources();
};

#endif