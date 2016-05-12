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
	if (character.getOxygenLevel(character.getX(), character.getY()) < 40)
	{ // If oxygen is too low the character loses health
		character.health--;
	}
	
	else if (character.getOxygenLevel(character.getX(), character.getY()) > 80)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(character.walkSpeed);
	}
	else if (keyboardState[SDL_SCANCODE_W] || keyboardState[SDL_SCANCODE_A] || keyboardState[SDL_SCANCODE_S] || keyboardState[SDL_SCANCODE_D] && character.getOxygenLevel(character.getX(), character.getY()) > 10)
	{// Character can still move but if oxygen is below 0 they can't move
		character.state = std::make_shared<PlayerControlledState>();
		character.moveCharacter(keyboardState);
	}
}