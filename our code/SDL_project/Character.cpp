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

void Character::moveCharacter()
{
	/*if (keyboardInput[SDL_SCANCODE_UP] || keyboardInput[SDL_SCANCODE_W])
	{
		//check cell state
		if (getY() + getSpeed() > 0) //Only lets character move if the next cell is a room and is on screen
		{
			setY(getY() + getSpeed());
			//updates chracter position depending on direction
		}
	}
	else if (keyboardInput[SDL_SCANCODE_DOWN] || keyboardInput[SDL_SCANCODE_S])
	{
		setY(getY() - getSpeed());
	}

	else if (keyboardInput[SDL_SCANCODE_LEFT] || keyboardInput[SDL_SCANCODE_A])
	{
		if (getX() + getSpeed() > 0)
			setX(getX() - getSpeed());
	}
	else if (keyboardInput[SDL_SCANCODE_RIGHT] || keyboardInput[SDL_SCANCODE_D])
	{
		setX(getX() + getSpeed());
	}*/
	setY(getY());
		
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
