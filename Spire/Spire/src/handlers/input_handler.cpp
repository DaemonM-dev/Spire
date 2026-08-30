#include "../../include/handlers/input_handler.hpp"

void InputHandler::GetCommandBits(Command t_cmd, char* t_buffer)
{
    for (int i = CMD_COUNT - 1; i >= 0; i--)
    {
        t_buffer[CMD_COUNT - 1 - i] = (t_cmd & (1u << i)) ? '1' : '0';
    }
    t_buffer[CMD_COUNT] = '\0';
}

bool InputHandler::IsCommandActive(Command t_cmd, Command t_filter)
{
    return (t_cmd & t_filter) != 0;
}

Command InputHandler::PollInput()
{
    Command command = CMD_NONE;

    if (IsGamepadAvailable(0)) // Controller Inputs
    {
        int gamepad = 0;

        float stick_Left_X = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);
        float stick_Left_Y = GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);

        bool d_pad_UP = IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP);
        bool d_pad_DOWN = IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        bool d_pad_LEFT = IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        bool d_pad_RIGHT = IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);

        bool gamepadActive =
            fabsf(stick_Left_X) > STICK_DEADZONE_THRESHOLD ||
            fabsf(stick_Left_Y) > STICK_DEADZONE_THRESHOLD ||
            d_pad_UP || d_pad_DOWN || d_pad_LEFT || d_pad_RIGHT;

        if (gamepadActive)
        {
            // D-pad movement
            if (d_pad_UP) { command = (Command)(command | CMD_MOVE_UP); }
            if (d_pad_DOWN) { command = (Command)(command | CMD_MOVE_DOWN); }
            if (d_pad_LEFT) { command = (Command)(command | CMD_MOVE_LEFT); }
            if (d_pad_RIGHT) { command = (Command)(command | CMD_MOVE_RIGHT); }

            if (fabsf(stick_Left_Y) > STICK_DEADZONE_THRESHOLD || fabsf(stick_Left_X) > STICK_DEADZONE_THRESHOLD)
            {
                if (stick_Left_Y < -MOVE_VERTICAL_THRESHOLD) { command = (Command)(command | CMD_MOVE_UP); }
                if (stick_Left_Y > MOVE_VERTICAL_THRESHOLD) { command = (Command)(command | CMD_MOVE_DOWN); }
                if (stick_Left_X < -MOVE_HORIZONTAL_THRESHOLD) { command = (Command)(command | CMD_MOVE_LEFT); }
                if (stick_Left_X > MOVE_HORIZONTAL_THRESHOLD) { command = (Command)(command | CMD_MOVE_RIGHT); }
            }
        }
    }
    else
    {
        // Keyboard input
        if (IsKeyDown(KEY_W)) { command = (Command)(command | CMD_MOVE_UP); }
        if (IsKeyDown(KEY_S)) { command = (Command)(command | CMD_MOVE_DOWN); }
        if (IsKeyDown(KEY_A)) { command = (Command)(command | CMD_MOVE_LEFT); }
        if (IsKeyDown(KEY_D)) { command = (Command)(command | CMD_MOVE_RIGHT); }
    }

    return command;
}
