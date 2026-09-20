#include "player.hpp"

Player::Player(const Texture2D& texture) : spritesheet(texture){

    state = IDLE;
    direction = DOWN;

    width = 128;
    height = 128;
    x = 960 / 2;
    y = 540 / 2;
    normalSpeed = 120;
    angleSpeed = normalSpeed * 0.75f;
    activeSpeed = normalSpeed;

    row = 0;
    col = 0;

    totalFrames = 6;
    frameWidth = 64;
    frameHeight = 64;
    frameSpeed = 10; // Times per second
}

void Player::update(const float& dt){

    animate(dt);
}

void Player::changeDirection(const Direction& newDir){
    if(direction != newDir){
        frameCount = 0.0f;
        switch (state){
            case IDLE:
                totalFrames = 6;
                switch (newDir){
                    case UP:    row = 1; break;
                    case DOWN:  row = 0; break;
                    case LEFT:  row = 2; break;
                    case RIGHT: row = 2; break;
                }
            break;
            case MOVING:
                totalFrames = 4;
                switch (newDir){
                    case UP:    row = 4; break;
                    case DOWN:  row = 3; break;
                    case LEFT:  row = 5; break;
                    case RIGHT: row = 5; break;
                }
            break;
        }
        col = 0;
        direction = newDir;
    }
}

void Player::changeState(const PlayerState& newState){
    if(state != newState){
        frameCount = 0.0f;
        switch (newState){
            case IDLE:
                totalFrames = 6;
                frameSpeed = 10;
                switch (direction){
                    case UP:    row = 1; break;
                    case DOWN:  row = 0; break;
                    case LEFT:  row = 2; break;
                    case RIGHT: row = 2; break;
                }
            break;
            case MOVING:
                totalFrames = 4;
                frameSpeed = 14;
                switch (direction){
                    case UP:    row = 4; break;
                    case DOWN:  row = 3; break;
                    case LEFT:  row = 5; break;
                    case RIGHT: row = 5; break;
                }
            break;
        }
        col = 0;
        state = newState;
    }
}

void Player::draw(){
    if(direction != LEFT){
            DrawTexturePro(
            spritesheet,
            { (float)col * 64, (float)row * 64, frameWidth, frameHeight},
            { x, y, width, height},
            { 0.0f,0.0f },
            0.0f,
            RAYWHITE
        );
    } else {
            DrawTexturePro(
            spritesheet,
            { (float)col * 64, (float)row * 64, -frameWidth, frameHeight},
            { x, y, width, height},
            { 0.0f,0.0f },
            0.0f,
            RAYWHITE
        );
    }
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

void Player::move(const float& dt){
    if(state == IDLE){

        if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
            changeDirection(UP);
            upKeyPressed = true;
        } else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
            changeDirection(DOWN);
            downKeyPressed = true;
        } else if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
            changeDirection(LEFT);
            leftKeyPressed = true;
        } else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
            changeDirection(RIGHT);
            rightKeyPressed = true;
        }

        if(upKeyPressed || downKeyPressed || leftKeyPressed || rightKeyPressed){
            changeState(MOVING);
        }

    } else if (state == MOVING){

        if(IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)){ upKeyPressed = true; }
        if(IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)){ downKeyPressed = true; }
        if(IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)){ leftKeyPressed = true; } 
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){ rightKeyPressed = true; }

        if(upKeyPressed){
            changeDirection(UP);
        } else if (downKeyPressed){
            changeDirection(DOWN);
        } else if (leftKeyPressed){
            changeDirection(LEFT);
        } else if (rightKeyPressed){
            changeDirection(RIGHT);
        }

        if((upKeyPressed && (leftKeyPressed || rightKeyPressed)) || (downKeyPressed && (leftKeyPressed || rightKeyPressed))){
                activeSpeed = angleSpeed;
        } else if(activeSpeed != normalSpeed){
                activeSpeed = normalSpeed;
            }
        }

        if(upKeyPressed){
            y -= activeSpeed * dt;
            if(IsKeyReleased(KEY_UP)    || IsKeyReleased(KEY_W)){ upKeyPressed = false; }
        }
        if(downKeyPressed){
            y += activeSpeed * dt;
            if(IsKeyReleased(KEY_DOWN)  || IsKeyReleased(KEY_S)){ downKeyPressed = false; }
        }
        if(leftKeyPressed){
            x -= activeSpeed * dt;
            if(IsKeyReleased(KEY_LEFT)  || IsKeyReleased(KEY_A)){ leftKeyPressed = false; }
        }
        if(rightKeyPressed){
            x += activeSpeed * dt;
            if(IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D)){ rightKeyPressed = false; }
        }

        if(!upKeyPressed && !downKeyPressed && !leftKeyPressed && !rightKeyPressed){
            changeState(IDLE);
        }
}