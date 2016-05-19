#include "stdafx.h"
#include "Suffocating.h"

Suffocating::Suffocating()
{
}

Suffocating::~Suffocating()
{
}

void Suffocating::update(Character& character, const Uint8* keyboardState)
{
	//character.health = character.health - 0.4;
	if (character.health ==0)
	{
		character.state = std::make_shared<DeadState>();
	}	
	// If oxygenLevel is below the dangeroursOxygenLevel the character loses health 
	else if (character.getOxygenLevel(character.getX(), character.getY()) < character.dangeroursOxygenLevel)
	{
		character.health = character.health - 0.8;
	}
	// If the oxygenLevel reaches acceptableOxygenLevel the character changes to the Idle state and speeds up again 
	else if (character.getOxygenLevel(character.getX(), character.getY()) > character.acceptableOxygenLevel)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(character.walkSpeed);
	}
	// The character can still move in the Suffocating state but speed is reduced
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D])
	{
		character.moveCharacter(keyboardState);
		character.health = character.health - 0.4;
	}
	else
	{
		character.health = character.health - 0.4;
	}
}

void Suffocating::removeHealth(Character& character)
{
		character.health = character.health - 0.8;
}