#include "stdafx.h"
#include "Character.h"

Character::Character()
{
}


Character::~Character()
{
}


// If the player doesn't move the character it will start to move around the room in randomly selected directions
void Character::moveCharacter(PlayerInput::KeyboardDirections direction)
{ 
	// if the direction will keep the charcter on screen and is part of a room move Character down
	if (direction == PlayerInput::KeyboardDirections::Down && getY() + getSpeed() < windowHeight && isCellARoom(getX(), getY() + getSpeed()))
	{
		// If the Characer is wandering also check is the cell is a door
		if (isWandering == true && isCellADoor(getX(), getY() + getSpeed()))
			direction = static_cast<PlayerInput::KeyboardDirections>(rand() % 4);
		else
			setY(getY() + getSpeed());		
	}
	// if the direction will keep the charcter on screen and is part of a room move Character up
	else if (direction == PlayerInput::KeyboardDirections::Up && (getY() + getSpeed()) > 0 && isCellARoom(getX(), getY() - getSpeed()))
	{
		// If the Characer is wandering also check is the cell is a door
		if (isWandering == true && isCellADoor(getX(), getY() - getSpeed()))
			direction = static_cast<PlayerInput::KeyboardDirections>(rand() % 4);
		else
			setY(getY() - getSpeed());
	}
	// if the direction will keep the charcter on screen and is part of a room move Character right
	else if (direction == PlayerInput::KeyboardDirections::Right && (getX() + getSpeed()) < windowWidth && isCellARoom(getX() + getSpeed(), getY()))
	{
		// If the Characer is wandering also check is the cell is a door
		if (isWandering == true && isCellADoor(getX() + getSpeed(), getY()))
			direction = static_cast<PlayerInput::KeyboardDirections>(rand() % 4);
		else
			setX(getX() + getSpeed());
	}
	// if the direction will keep the charcter on screen and is part of a room move Character left
	else if (direction == PlayerInput::KeyboardDirections::Left && (getX() - getSpeed()) > 0 && isCellARoom(getX() - getSpeed(), getY()))
	{
		// If the Characer is wandering also check is the cell is a door
		if (isWandering == true && isCellADoor(getX() - getSpeed(), getY()))
			direction = static_cast<PlayerInput::KeyboardDirections>(rand() % 4);
		else
			setX(getX() - getSpeed());
	}
	// If Character cannot move in current direction randomly choose a new one
	else if (isWandering == true)
	{
		direction = static_cast<PlayerInput::KeyboardDirections>(rand() % 4);
	}
}

// Checks to see if a cell is a room
bool Character::isCellARoom(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isRoom;
}

// Checks to see if a cell is a room
bool Character::isCellADoor(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isDoor;
}

// Gets the oxygen level of the specified cell
int Character::getOxygenLevel(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->oxygenLevel;
}

// Checks whether the cell is the goal cell
bool Character::reachedGoal(int x, int y)
{
	int xCell = x / currentRoom->getCellSize();
	int yCell = y / currentRoom->getCellSize();
	return currentRoom->grid[xCell][yCell]->isGoal;
}