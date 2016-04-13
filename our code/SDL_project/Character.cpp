#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::update()
{

}

void Character::moveCharacter(const Uint8* keyboardState)
{
	/*if (keyboardState[SDL_SCANCODE_W])
	{
		//check cell state
		if (getY() + getSpeed() > 0) //Only lets character move if the next cell is a room and is on screen
		{
			setY(getY() + getSpeed());
			//updates chracter position depending on direction
		}
	}*/
	if (keyboardState[SDL_SCANCODE_W] && getY() + getSpeed() > 0)
	{
		setY(getY() - getSpeed());
	}

	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800) //Change to pass in screen width
	{
		setY(getY() + getSpeed());
	}

	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0)
	{
		if (getX() + getSpeed() > 0)
			setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800)
	{
		setX(getX() + getSpeed());
	}
	//setX(getX() + 2);
		
}

void Character::reactToFire()
{
}

void Character::reactToOxygen()
{

}
void Character::wanderAroundRoom()
{

}
