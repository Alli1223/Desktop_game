#pragma once
#include "CharacterState.h"
class GameControlledState :
	public CharacterState
{
public:
	//Base for states where the character moves without input from the player
	//such as the fire state and the wandering state
	GameControlledState();
	~GameControlledState();
};

