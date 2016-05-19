#pragma once
#include "CharacterState.h"
#include "DeadState.h"
#include "IdleState.h"
//! The suffocating class is for when the character is on a cell with a low oxygen level
/*!
This class alters the characters speed and health depending on the oxygen level of the cell it's currently on 
*/

class Suffocating :
	public CharacterState
{
public:
	//! A constructor
	Suffocating();
	//! A destructor
	~Suffocating();
	//! The two oxygen levels that are used to change alter Character's state
	int acceptableOxygenLevel = 50, dangeroursOxygenLevel = 20;
	//! The update function that checks and updates the character state.
	/*!
	Runs on every frame of the game to check the level and update the character state.
	It takes in the character which needs it's state updating and keyboardState to check whether the user has
	pressed the keyboard since the last update
	*/
	void update(Character& character, const Uint8* keyboardState);
};

