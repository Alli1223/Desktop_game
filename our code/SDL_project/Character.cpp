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
	{//If the W key is pressed and the character won't be moved off screen move the character
		if (isCellARoom(getX(), getY() + getSpeed())) //need to stop it checking outside of grid because causes error
			setY(getY() - getSpeed());
	}

	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800) //Will change to pass in screen height
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
{
	health = health - 1;
	//TODO: Make character move away from fire
}

void Character::wanderAroundRoom()
{
	//TODO: Check surrounding cells and then make character to "wander" in one direction until they hit a wall or change state
	//if (isCellARoom(getX(), getY() - getSpeed()) && (getY() - getSpeed()) > 0 ) 
	//	setY(getY() - getSpeed());
	if (isCellARoom(getX(), getY() + getSpeed()) && (getY() + getSpeed()) < 800) //need to change to pass in screen dimensions
		setY(getY() + getSpeed());
	else if (isCellARoom(getX() - getSpeed(), getY()))
		setX(getX() - getSpeed());
	else if (isCellARoom(getX() + getSpeed(), getY()))
		setX(getX() + getSpeed());
	
}

bool Character::isCellARoom(int x, int y)
{//Checks to see if a cell is a room
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isRoom;
}

bool Character::isCellOnFire(int x, int y)
{//Checks to see if a cell is on fire
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->onFire;
}

int Character::getOxygenLevel(int x, int y)
{//Gets the oxygen level of the specified cell
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->oxygenLevel;
}

