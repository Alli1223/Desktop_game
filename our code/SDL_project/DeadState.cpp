#include "stdafx.h"
#include "DeadState.h"


DeadState::DeadState()
{
}


DeadState::~DeadState()
{
}

void DeadState::update(Character& character)
{
	//If the character runs out of health they enter the dead state, the characte can't change from this state back to another
	//Will check to see if other characters are still alive
	character.isAlive = false;
}
