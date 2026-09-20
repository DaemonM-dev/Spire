#include "player.hpp"

Player::Player(const Texture2D& texture) : spritesheet(texture){

    state = IDLE;
    direction = DOWN;

    width = 128;
    height = 128;
    x = 960 / 2;
    y = 540 / 2;

    row = 0;
    col = 0;

    totalFrames = 6;
    frameSpeed = 10; // Times per second
}

void Player::update(const float& dt){

    animate(dt);
}

void Player::draw(){
    DrawTexturePro(
        spritesheet,
        { (float)col * 64, (float)row * 64, 64, 64},
        { x, y, width, height},
        { 0.0f,0.0f },
        0.0f,
        RAYWHITE
    );
}

void Player::animate(const float& dt){
    frameCount += frameSpeed * dt;
    if(frameCount >= 1.0f){
        col++;
        if(col > totalFrames - 1){
            col = 0;
        }
        frameCount = 0;
    }
}