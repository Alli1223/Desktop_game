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
	//Will check to see if other character are still alive
	character.isAlive = false;
}
