#include "stdafx.h"
#include "WanderingState.h"


WanderingState::WanderingState()
{
}


WanderingState::~WanderingState()
{
}

void WanderingState::update(Character& character, Grid grid)
{
	count = count + 1;
	//Get surrounding cell states
	//Move into a cell that is a room/not on fire/has sufficient oxygen
}