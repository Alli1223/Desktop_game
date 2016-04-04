#pragma once
#include "MovingState.h"
class FireState : public MovingState
{
public:
	FireState();
	~FireState();

	void update(Character& character, Grid grid);
};

