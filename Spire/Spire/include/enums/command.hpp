#ifndef COMMAND_HPP
#define COMMAND_HPP
typedef enum Command{
	CMD_NONE = 0,
	CMD_MOVE_UP = 1 << 0,
	CMD_MOVE_DOWN = 1 << 1,
	CMD_MOVE_LEFT = 1 << 2,
	CMD_MOVE_RIGHT = 1 << 3,
	CMD_COUNT = 4
} Command;
#endif
