#pragma once
#include"Character.h"

class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	virtual void update(Character& character) = 0;
};

