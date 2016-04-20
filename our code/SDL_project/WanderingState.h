#pragma once
#include "GameControlledState.h"
class WanderingState :
	public GameControlledState
{
public:
	WanderingState();
	~WanderingState();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

