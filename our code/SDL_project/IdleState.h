#pragma once
#include"CharacterState.h"
#include "DeadState.h"
#include "SuffocatingState.h"
#include"PlayerControlledState.h"
#include"WanderingState.h"
#include"ReachedGoalState.h"

//!  The IdleState is for when there is no danger and the character is not controlling the player 
/*!
This class is inherits from the CharacterState class.  The character does not do anything in the IdleState it just checks
for when it should update to another state
*/

class IdleState: public CharacterState
{
public:
	//! A constructor
	IdleState();
	//! A destructor
	~IdleState();

	
	// Used to measure how long the character has been in the Idle state
	double timer = 0;
	//! Used to add to the timer
	double FRAME_RATE = 60;
	//! The update function that checks and updates the character state.
	/*!
	Runs on every frame of the game to check the level and update the character state.
	It takes in the character which needs it's state updating and keyboardState to check whether the user has
	pressed the keyboard since the last update
	*/
	void update(Character& character, const Uint8* keyboardState);
};

