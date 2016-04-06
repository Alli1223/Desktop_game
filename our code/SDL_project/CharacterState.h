#pragma once
#include"Character.h"
#include"Grid.h"

class CharacterState
{
public:
	CharacterState();
	~CharacterState();

	int count;  //For testing

	virtual void update(Character& character, Grid grid);
    //Will check on each frame what state the character should be in
	//And will call the corresponding function from Character
};