#pragma once
#include"CharacterState.h"
#include"Character.h"

class DeadState: public CharacterState
{
public:
	DeadState();
	~DeadState();

	int deadTime;

	void update(Character& character);
};

