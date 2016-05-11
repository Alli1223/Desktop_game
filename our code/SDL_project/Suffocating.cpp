#include "stdafx.h"
#include "Suffocating.h"


Suffocating::Suffocating()
{
}


Suffocating::~Suffocating()
{
}

void Suffocating::update(Character& character)
{
	character.setSpeed(character.suffocatingSpeed);
	if (character.getOxygenLevel(character.getX(), character.getY()) > 70)
	{ // If the oxygen level gets high enough it switches back to idle state
		character.state = std::make_shared<IdleState>();
		character.setSpeed(character.walkSpeed);
	}
}