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

	//! The update function that checks and updates the character state.
	/*!
	Runs on every frame of the game to check the level and update the character state.
	It takes in the character which needs it's state updating and keyboardState to check whether the user has
	pressed the keyboard since the last update
	*/
	void update(Character& character, const Uint8* keyboardState);
};

