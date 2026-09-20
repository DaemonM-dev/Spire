#ifndef GAME_HPP
#define GAME_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <raylib.h>
#include "component.hpp"
#include "player.hpp"

class Game{
    public:

    void Run();

    private:

    RenderTexture2D gameWindow;
    Vector2 gameWindowSize;
    Vector2 gameWindowPos;
    Vector2 screenSize;
    float gameScale;

    std::map<std::string, const Texture2D> textureMap;

    std::unique_ptr<TextureComponent> sunset{nullptr};
    std::unique_ptr<TextureComponent> columnPath{nullptr};

    std::unique_ptr<TextureComponent> cloud1_1{nullptr};
    std::unique_ptr<TextureComponent> cloud2_1{nullptr};
    std::unique_ptr<TextureComponent> cloud3_1{nullptr};

    std::unique_ptr<TextureComponent> cloud1_2{nullptr};
    std::unique_ptr<TextureComponent> cloud2_2{nullptr};
    std::unique_ptr<TextureComponent> cloud3_2{nullptr};

    std::unique_ptr<Player> player{nullptr};

    void Initialize();
    void Update(const float& dt);
    void UpdateRenderWindow();
    void DrawRenderWindow();
    void Draw();
    void FreeResources();
};

#endif