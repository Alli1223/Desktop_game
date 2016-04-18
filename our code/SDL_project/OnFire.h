#pragma once
#include "GameControlledState.h"
class OnFire :
	public GameControlledState
{
public:
	//If the character in on or one cell away from fire they'll run away
	OnFire();
	~OnFire();

	void update(Character& character, Grid grid, const Uint8* keyboardState);
};

