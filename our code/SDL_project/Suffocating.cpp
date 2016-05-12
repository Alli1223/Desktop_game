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
	character.setSpeed(1);  // TODO: Change to a variable and use framerate
	if (character.getOxygenLevel(character.getX(), character.getY()) > 50)
	{
		character.state = std::make_shared<IdleState>();
		character.setSpeed(2);
	}
}