#include "stdafx.h"
#include "PlayerInput.h"


PlayerInput::PlayerInput()
{
}


PlayerInput::~PlayerInput()
{
}

void PlayerInput::handleKeyBoardInput(const Uint8* keyboardState)
{
	if (keyboardState[settings.DEFAULT_UP] || keyboardState[settings.ALTERNATE_UP])
	{
		currentDirection = KeyboardDirections::Up;
	}
	else if (keyboardState[settings.DEFAULT_DOWN] || keyboardState[settings.ALTERNATE_DOWN])
	{
		currentDirection = KeyboardDirections::Down;
	}
	else if (keyboardState[settings.DEFAULT_LEFT] || keyboardState[settings.ALTERNATE_LEFT])
	{
		currentDirection = KeyboardDirections::Left;
	}
	else if (keyboardState[settings.DEFAULT_RIGHT] || keyboardState[settings.ALTERNATE_UP])
	{
		currentDirection = KeyboardDirections::Right;
	}
	else
	{
		currentDirection = KeyboardDirections::None;

		currentDirection = static_cast<KeyboardDirections>(rand() % 4);

	}
}
