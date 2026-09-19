#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <raylib.h>

class TextureComponent {

    public:

        const Texture2D& texture;
        float width;
        float height;
        float xPos;
        float yPos;

        TextureComponent(const Texture2D& texture, float width, float height, float x, float y);

        void move(float x, float y);
        void setPosition(float x, float y);
        void draw();

    private:
};


#endif