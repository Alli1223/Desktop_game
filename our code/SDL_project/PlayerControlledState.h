#pragma once
#include "CharacterState.h"
class PlayerControlledState :
	public CharacterState
{
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, Grid grid);
};

