#include "stdafx.h"
#include "IdleState.h"



IdleState::IdleState()
{
	count = 1;
}


IdleState::~IdleState()
{
}

void IdleState::update(Character& character, Grid grid, const Uint8* keyboardState)
{
	//Idle state is for the start and the a for when the character has just stopped being controlled by the player
	timer = timer + (1 / FRAME_RATE); 
	
	//If character is dead
	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
		count = 2;
	}
	else if (character.oxygenLevel < 50)
	{
		character.state = std::make_shared<LowOxygenState>();
		character.setSpeed(1);
		count = 3;
	}
	else if (keyboardState != SDL_GetKeyboardState(nullptr))
	{
		character.state = std::make_shared<PlayerControlledState>();
		//character.moveCharacter();
		count = 4;
	}


}
