#pragma once
#include "CharacterState.h"
#include "PlayerControlledState.h"
#include "LowOxygenState.h"
#include "DeadState.h"
#include "IdleState.h"

class GameControlledState :
	public CharacterState
{
public:
	//Base for states where the character moves without input from the player
	//such as the fire state and the wandering state
	//MAYBE NOT NEEDED???
	GameControlledState();
	~GameControlledState();
};

