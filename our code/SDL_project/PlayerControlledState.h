#pragma once
#include "CharacterState.h"
#include "IdleState.h"
#include "DeadState.h"
#include "Suffocating.h"
#include"OnFire.h"

class PlayerControlledState :
	public CharacterState
{
	
public:
	PlayerControlledState();
	~PlayerControlledState();

	void update(Character& character, const Uint8* keyboardState);
};

