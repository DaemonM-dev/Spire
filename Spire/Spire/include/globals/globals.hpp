#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include <iostream>
#include <raylib.h>
// Signed Integers
// int8_t - (1 Byte)  - MIN: -128   / MAX: 127
// int16_t - (2 Byte) - MIN: -32768 / MAX: 32767

// Un-signed Integers
// uint8_t - (1 Byte)  - MIN: 0 / MAX: 255
// uint16_t - (2 Byte) - MIN: 0 / MAX: 65535

class Vector2ui {
public:
	Vector2ui(uint16_t x, uint16_t y) : x(x), y(y) {};
	uint16_t x;
	uint16_t y;
};

class Vector2si {
public:
	Vector2si(int16_t x, int16_t y) : x(x), y(y) {};
	int16_t x;
	int16_t y;
};

static const Vector2 SCREEN_SIZE{ 1920.0f,1080.0f};
static const Vector2ui SCREEN_SIZEui{ 1920,1080 };
#endif
