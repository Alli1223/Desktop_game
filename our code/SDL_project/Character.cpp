#include "stdafx.h"
#include "Character.h"

Character::Character()
{
}


Character::~Character()
{
}

void Character::moveCharacter(const Uint8* keyboardState)
{// This function should only be called if WASD is pressed, it then checks to see which one is pressed and moves the character accordingly
	 
	if (keyboardState[SDL_SCANCODE_W] && getY() - getSpeed() > 0 && isCellARoom(getX(), getY() - getSpeed()))
	{ // If the W key is pressed and the character won't be moved off screen move the character
		setPreviousX(getX());
		setPreviousY(getY());
		setY(getY() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800 && isCellARoom(getX(), getY() + getSpeed())) //Will change to pass in screen dimensions
	{
		setPreviousX(getX());
		setPreviousY(getY());
		setY(getY() + getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0 && isCellARoom(getX() - getSpeed(), getY()))
	{
		setPreviousX(getX());
		setPreviousY(getY());
		setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800 && isCellARoom(getX() + getSpeed(), getY()))
	{
		setPreviousX(getX());
		setPreviousY(getY());
		setX(getX() + getSpeed());
	}
}

void Character::reactToFire()
{// This function will make the character run in the opposite direction to where the fire is
	health = health - 0.1; //loses health
	setX(previousX);
	setY(previousY);
}


void Character::wanderAroundRoom()
{ // Makes the character move around the room on it's own it the player doesn't direct it for a certain amount of time

  /* In progress gets surronding cells before deciding on a path
    auto surroundingCells = getSurroundingCells();
	for (int i = 0; i < surroundingCells.size(); i++)
	{
		if (!isCellARoom(surroundingCells[i]->getX(), surroundingCells[i]->getY()))
		{
			surroundingCells.erase(surroundingCells.begin() + i);
		}
		bool test = checkLocation(surroundingCells[i]->getX(), surroundingCells[i]->getY());
		if (!test)
		{
			setPreviousLocation(getX(), getY());
			setY(surroundingCells[i]->getY());
			setX(surroundingCells[i]->getX());
			break;
		}
		
		else if (!checkLocation(surroundingCells[i]->getX() + getSpeed(), surroundingCells[i]->getY()))
		{
			setPreviousLocation(getX(), getY());
			setX(getX() + getSpeed());
		}

	}*/

	

	//TODO: Change to pass in window dimensions
	if (isCellARoom(getX(), getY() + getSpeed())&& !isCellADoor(getX(), getY() + getSpeed()) && (getY() + getSpeed()) < 800 - getSize() && !checkLocation(getX(), getY() + getSpeed()))
	{
		setPreviousLocation(getX(), getY());
		setY(getY() + getSpeed());		
	}
	else if (isCellARoom(getX() + getSpeed(), getY()) && !isCellADoor(getX() + getSpeed(), getY()) && (getX() + getSpeed()) < 800 - getSize() && !checkLocation(getX() + getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() + getSpeed());
	}
	else if (isCellARoom(getX(), getY() - getSpeed()) && !isCellADoor(getX(), getY() - getSpeed()) && (getY() + getSpeed()) > 0 + getSize() && !checkLocation(getX(), getY() - getSpeed()))
	{
		setPreviousLocation(getX(), getY());
		setY(getY() - getSpeed());
	}	
	else if (isCellARoom(getX() - getSpeed(), getY()) && !isCellADoor(getX() - getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() - getSpeed());
	}
}

bool Character::isCellARoom(int x, int y)
{// Checks to see if a cell is a room
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isRoom;
}

bool Character::isCellADoor(int x, int y)
{// Checks to see if a cell is a room
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isDoor;
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

void Character::setPreviousLocation(int x, int y)
{ //Sets the current x and y as the previous x and y
	setPreviousX(x);
	setPreviousY(y);
}

bool Character::checkLocation(int x, int y)
{ //Check to see if the passed in location is the same as the previous location
	//This will be used in the wandering state to make sure the character doesn't get stuck
	if (x == getPreviousX() && y == getPreviousY())
		return true;
	else
		return false;
}