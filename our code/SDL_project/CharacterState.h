#pragma once
#include"Character.h"
#include"Grid.h"


class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	double timer = 0; //used when entering or using IdleState
	
	virtual void update(Character& character, Grid grid, const Uint8* keyboardState);
    //Will check on each frame what state the character should be in
	//And will call the corresponding function from Character

};