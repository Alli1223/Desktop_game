#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
}


DeadState::~DeadState()
{
}

// Character can not leave the dead state 
void DeadState::update(Character& character, PlayerInput::KeyboardDirections direction)
{
	character.isAlive = false;
}
