#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <raylib.h>
#include <iostream>

typedef enum PlayerState {
    IDLE,
    WALKING
} PlayerState;

typedef enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

class Player{

    public:

        Player(const Texture2D& texture);

        void update(const float& dt);
        void draw();

    private:

    Texture2D spritesheet;
    PlayerState state;
    Direction direction;

    float width;
    float height;
    float x;
    float y;

    float frameCount;
    float frameSpeed;   // Frames per second
    int totalFrames;    // Frames per animation
    int row;
    int col;

    void animate(const float& dt);
};

#endif