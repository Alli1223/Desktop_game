#pragma once
#include "CharacterState.h"
class MovingState :
	public CharacterState
{
public:
	MovingState();
	~MovingState();

	void update(Character& character, Grid grid);

};

