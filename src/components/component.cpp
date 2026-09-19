#include "component.hpp"

TextureComponent::TextureComponent(const Texture2D& texture, float width, float height, float x, float y) :
 texture(texture), width(width), height(height), xPos(x), yPos(y) {}

void TextureComponent::move(float x, float y){
    xPos += x;
    yPos += y;
}
void TextureComponent::setPosition(float x, float y){
    xPos = x;
    yPos = y;
}
void TextureComponent::draw() const{
    DrawTexturePro(texture,
        {0.0f, 0.0f, (float)texture.width, (float)texture.height},
        {xPos, yPos, width, height},
        {0.0f, 0.0f},
        0.0f,
        RAYWHITE
        );
}