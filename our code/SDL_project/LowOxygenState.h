#pragma once
#include "PlayerControlledState.h"
class LowOxygenState : public PlayerControlledState
{
public:
	LowOxygenState();
	~LowOxygenState();

	void update(Character& character, Grid grid);
};

