#pragma once
#include "CharacterState.h"
//! The character enters this class once they have reached the end goal

class ReachedGoalState :
	public CharacterState
{
public:
	//! A constructor
	ReachedGoalState();
	//! A destructor
	~ReachedGoalState();
};

