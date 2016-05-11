#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
}


DeadState::~DeadState()
{
}

void DeadState::update(Character& character, const Uint8* keyboardState)
{
	//If the character runs out of health they enter the dead state
	//The character can't exit this state
	character.isAlive = false;
}
