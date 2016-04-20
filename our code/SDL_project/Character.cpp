#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::moveCharacter(const Uint8* keyboardState)
{//This function should only be called if WASD is pressed, it then checks to see which one is pressed and moves the character accordingly
	
	if (keyboardState[SDL_SCANCODE_W] && getY() + getSpeed() > 0)
	{//If the W key is pressed and the character won't be moved off screen move the character
		if (isCellARoom(getX(), getY() + getSpeed())) //need to stop it checking outside of grid because causes error
			setY(getY() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800) //Will change to pass in screen dimensions
	{
		if (isCellARoom(getX(), getY() + getSpeed()))
			setY(getY() + getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0)
	{
		if (isCellARoom(getX() - getSpeed(), getY()))
			setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800)
	{
		if (isCellARoom(getX() + getSpeed(), getY()))
			setX(getX() + getSpeed());
	}
}

void Character::reactToFire()
{// This function will make the character run in the opposite direction to where the fire is
	health = health - 1;
	//TODO: Make character move away from fire
	//Adapt wandering function to make character move 
}

void Character::wanderAroundRoom()
{//Makes the character move around the room on it's own it the player doesn't direct it for a certain amount of time
	//Make wandering more natural than just moving around the edge of the room
	if (isCellARoom(getX(), getY() - getSpeed()) && (getY() - getSpeed()) > 0 ) 
		setY(getY() - getSpeed());
	if (isCellARoom(getX(), getY() + getSpeed()) && (getY() + getSpeed()) < 800) //need to change to pass in screen dimensions
		setY(getY() + getSpeed());
	else if (isCellARoom(getX() - getSpeed(), getY()))
		setX(getX() - getSpeed());
	else if (isCellARoom(getX() + getSpeed(), getY()))
		setX(getX() + getSpeed());
	
}

bool Character::isCellARoom(int x, int y)
{// Checks to see if a cell is a room
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isRoom;
}

bool Character::isCellOnFire(int x, int y)
{// Checks to see if a cell is on fire
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->onFire;
}

int Character::getOxygenLevel(int x, int y)
{// Gets the oxygen level of the specified cell
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->oxygenLevel;
}
