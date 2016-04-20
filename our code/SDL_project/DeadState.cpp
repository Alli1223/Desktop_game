#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
}


DeadState::~DeadState()
{
}

void DeadState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	//If the character runs out of health they enter the dead state, the characte can't change from this state back to another
	//TODO: Will check to see if other characters are still alive
	//TODO: Change the sprite used
	character.isAlive = false;
}
