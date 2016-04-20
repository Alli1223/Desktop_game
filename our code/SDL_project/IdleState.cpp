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
	
	
	if (character.health == 0)
	{//When health = 0 the character enters the dead state
		character.state = std::make_shared<DeadState>();
		character.isAlive = false;
		count = 2;
	}
	else if (character.getOxygenLevel(character.getX(), character.getY()) < 50)
	{//If the oxygen goes beneath a certain level the character slows down 
		character.state = std::make_shared<LowOxygenState>();
		character.setSpeed(1);
		count = 3;
	}
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{
		character.state = std::make_shared<PlayerControlledState>();
		character.moveCharacter(keyboardState);
		count = 4;
	}
	else if (timer > 2)
	{
		count = 5;
		character.state = std::make_shared<WanderingState>();
		character.wanderAroundRoom();
	}
	/*else if (cellstate.isFire = true)
	{
		character.state = std::make_shared<RoomOnFireState>();
		character.reactToFire()
	}*/
	
}
