#include "stdafx.h"
#include "WanderingState.h"

WanderingState::WanderingState()
{
}


WanderingState::~WanderingState()
{
}

void WanderingState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	character.wanderAroundRoom();
	//TODO: Store previous location
}
