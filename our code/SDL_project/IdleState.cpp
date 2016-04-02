#include "stdafx.h"
#include "IdleState.h"



IdleState::IdleState()
{
}


IdleState::~IdleState()
{
}

void IdleState::update(Character& character)
{
	//Idle state is for the start and the a for when the character has just stopped being controlled by the player
	timer = timer + (1 / FRAME_RATE); 

	if (character.health == 0)
		character.state = std::make_shared<DeadState>();
		//No function to call as character does nothing when dead
	//else if (timer < 5)
		//character.state = std::make_shared<WanderingState>();
	//else if (keyboardState != nullptr)
		//character.state = std::make_shared<PlayerControlledState>();
}
