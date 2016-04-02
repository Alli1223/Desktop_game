#include "stdafx.h"
#include "IdleState.h"


IdleState::IdleState()
{
}


IdleState::~IdleState()
{
}

void IdleState::update(Character& character, Grid grid)
{
	//Idle state is for the start and the a for when the character has just stopped being controlled by the player
	timer = timer + (1 / FRAME_RATE); 

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	//If character is dead
	if (character.health == 0)
		character.state = std::make_shared<DeadState>();
		//No function to call as character does nothing when dead
	//If character is on fire
	else if (grid.grid[character.getX()][character.getY()]->onFire)
	{
		character.state = std::make_shared<FireState>();
		character.reactToFire();
	}
	//If character is in area of low oxygen
	else if (grid.grid[character.getX()][character.getY()]->oxygenLevel < 80)
	{
		character.state = std::make_shared<LowOxygenState>();
		character.reactToOxygen();
	}
	//If user has interacted with character for over 5 seconds
	else if (timer < 5)
	{
		character.state = std::make_shared<WanderingState>();
		character.wanderAroundRoom();
	}
	//If user has pressed a key on the keyboard
	else if (keyboardState != nullptr)
	{
		character.state = std::make_shared<PlayerControlledState>();
		character.playerControlled();
	}
		
}
