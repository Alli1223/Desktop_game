#pragma once
#include"Character.h"

class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	void update(); //Will check on each frame what state the character should be in
	//And will call the corresponding function from Character
};

