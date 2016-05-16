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
		setPreviousLocation(getX(), getY());
		setY(getY() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_S] && getY() + getSpeed() < 800 && isCellARoom(getX(), getY() + getSpeed())) //Will change to pass in screen dimensions
	{
		setPreviousLocation(getX(), getY());
		setY(getY() + getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_A] && getX() + getSpeed() > 0 && isCellARoom(getX() - getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() - getSpeed());
	}
	else if (keyboardState[SDL_SCANCODE_D] && getX() + getSpeed() < 800 && isCellARoom(getX() + getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() + getSpeed());
	}
}

int Character::getRandomNumber(int smallestValue, int largestValue)
{
	std::srand(time(nullptr));
	return (rand() % (largestValue - smallestValue)) + smallestValue;
}

void Character::wanderAroundRoom()
{ // Makes the character move around the room on it's own it the player doesn't direct it for a certain amount of time
	direction = getRandomNumber(0, 4);
	if (direction == 0 && getY() + getSpeed() < 800 - getSize() && canWanderInRoom(getX(), getY() + getSpeed()))
	{//Up
		setPreviousLocation(getX(), getY());
		setY(getY() + getSpeed());		
	}
	else if (direction == 1 && (getY() + getSpeed()) > 0 + getSize() && canWanderInRoom(getX(), getY() - getSpeed()))
	{//Down
		setPreviousLocation(getX(), getY());
		setY(getY() - getSpeed());
	}
	else if (direction == 2 && (getX() + getSpeed()) < 800 - getSize() && canWanderInRoom(getX() + getSpeed(), getY()))
	{//Right
		setPreviousLocation(getX(), getY());
		setX(getX() + getSpeed());
	}
	else if (direction == 3 && (getX() - getSpeed()) > 0 && canWanderInRoom(getX() - getSpeed(), getY()))
	{//Left
		setPreviousLocation(getX(), getY());
		setX(getX() - getSpeed());
	}
	else
	{
		direction = getRandomNumber(0, 4);
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

bool Character::canWanderInRoom(int x, int y)
{ //Character can only wander around a room and can't go through door
	if (isCellARoom(x, y) && !isCellADoor(x, y) /*&& !checkLocation(x, y)*/)
	{
		return true;
	}
	else
		return false;
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
//This will be used in the wandering state to make sure the character doesn't get stuck jumping backwards and forwards
	if (x == getPreviousX() && y == getPreviousY())
		return true;
	else
		return false;
}