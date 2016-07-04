#pragma once
#include "GameSettings.h"
class PlayerInput
{
public:
	PlayerInput();
	~PlayerInput();

	GameSettings settings;

	enum class KeyboardDirections {Up, Down, Left, Right, None};
	KeyboardDirections currentDirection;
	KeyboardDirections previousDirection;

	void handleKeyBoardInput(const Uint8* keyboardState);
};

