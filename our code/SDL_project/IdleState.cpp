#include "stdafx.h"
#include "IdleState.h"
#include "DeadState.h"


IdleState::IdleState()
{
	count = 1;
}


IdleState::~IdleState()
{
}

void IdleState::update(Character& character, Grid grid)
{
	//Idle state is for the start and the a for when the character has just stopped being controlled by the player
	timer = timer + (1 / FRAME_RATE); 
	
	//const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	
	//If character is dead
	if (character.health == 0)
	{
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
	}

}
