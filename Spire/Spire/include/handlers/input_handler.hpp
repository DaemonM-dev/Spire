#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <math.h>

#include "../enums/command.hpp"

class InputHandler
{
public:

	void GetCommandBits(Command t_cmd, char* t_buffer);
	bool IsCommandActive(Command t_cmd, Command t_filter);

	Command PollInput();

private:
	float const FIRING_TRIGGER_TRESHOLD{ 0.05f };
	float const STICK_DEADZONE_THRESHOLD{ 0.05f };
	float const MOVE_VERTICAL_THRESHOLD{ 0.05f };
	float const MOVE_HORIZONTAL_THRESHOLD{ 0.05f };
	float const MOVE_DIAGONAL_THRESHOLD{ 0.05f };
};

#endif