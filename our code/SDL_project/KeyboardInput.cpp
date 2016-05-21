#include "stdafx.h"
#include "MoveDirection.h"


KeyboardInput::KeyboardInput()
{
}


KeyboardInput::~KeyboardInput()
{
}
bool KeyboardInput::validKeyPress(Character& character, const SDL_Scancode keyboardState)
{
	if (keyboardState == DEFAULT_UP || keyboardState == ALTERNATE_UP)
	{
		character.direction = 0;
		return true;
	}
	else if (keyboardState == DEFAULT_DOWN || keyboardState == ALTERNATE_DOWN)
	{
		character.direction = 1;
		return true;
	}
	else if (keyboardState == DEFAULT_LEFT|| keyboardState == ALTERNATE_LEFT)
	{
		character.direction = 2;
		return true;
	}
	else if (keyboardState == DEFAULT_RIGHT || keyboardState == ALTERNATE_RIGHT)
	{
		character.direction = 3;
		return true;
	}
	else
	{
		return false; 
	}
}
