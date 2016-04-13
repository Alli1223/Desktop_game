#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::moveCharacter(const Uint8* keyboardState)
{//This function should only be called if W A S or D is pressed, it then checks to see which one is pressed and moves the character accordingly
	//TODO: Need to check cell states to see if they're rooms or not

	if (keyboardState[SDL_SCANCODE_W] && getY() + getSpeed() > 0)
	{//If the W key is pressed and the character won't be moved off screen move teh character
		setY(getY() - getSpeed());
	}

	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800) //Will hange to pass in screen height
	{
		setY(getY() + getSpeed());
	}

	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0)
	{
		setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800)
	{
		setX(getX() + getSpeed());
	}
}

void Character::reactToFire()
{//Will make the character move away from fire
}

void Character::wanderAroundRoom()
{
	//Will make the character move around a room when not being controlled by player
}
