#pragma once
#include"CharacterState.h"
#include"Grid.h"
#include "DeadState.h"
#include "LowOxygenState.h"
#include"PlayerControlledState.h"
#include"WanderingState.h"


class IdleState: public CharacterState
{
public:
	IdleState();
	~IdleState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
	
	double timer = 0; //used to check how long the character has been in the idle state
	int END_IDLE_TIME = 5; //How long the character will still idle before switching to the wandering state
	double FRAME_RATE = 60;
};

