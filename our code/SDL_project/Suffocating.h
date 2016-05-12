#pragma once
#include "CharacterState.h"
#include "DeadState.h"
#include "IdleState.h"

class Suffocating :
	public CharacterState
{
public:
	Suffocating();
	~Suffocating();

	void update(Character& character, Grid grid);
};

