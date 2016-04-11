#pragma once
#include"CharacterState.h"
#include"Grid.h"
#include "DeadState.h"
#include "LowOxygenState.h"
#include"PlayerControlledState.h"


class IdleState: public CharacterState
{
public:
	IdleState();
	~IdleState();

	double timer = 0; //used to check how long the character has been in the idle state
	
	void update(Character& character, Grid grid);

	double FRAME_RATE = 60;
};

