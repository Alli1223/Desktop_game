#pragma once
#include "MovingState.h"
class WanderingState : public MovingState
{
public:
	WanderingState();
	~WanderingState();

	void update(Character& character, Grid grid);
};

