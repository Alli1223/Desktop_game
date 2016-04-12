#pragma once
#include "CharacterState.h"
#include "IdleState.h"
class PlayerControlledState :
	public CharacterState
{
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

