#pragma once
#include "SDL_project.h"
class PlayerEventHandler
{
public:
	PlayerEventHandler();
	~PlayerEventHandler();

	int getMousePosition() { return mouse_position; }
	int SetMousePosition(int new_mouse_position) { return mouse_position = new_mouse_position; }

private:
	int mouse_position;

};


