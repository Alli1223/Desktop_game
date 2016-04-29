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
 
	if (keyboardState[SDL_SCANCODE_W] && getY() - getSpeed() > 0)
	{//If the W key is pressed and the character won't be moved off screen move the character
		if (isCellARoom(getX(), getY() - getSpeed())) //need to stop it checking outside of grid because causes error
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


std::vector<std::shared_ptr<Coordinates>> Character::getSurroundingCells()
{// Creates a vector of the cells surrounding the character
	std::vector<std::shared_ptr<Coordinates>> surroundingCells;
	if (getY() - getSpeed() > 0)  //W
		surroundingCells.push_back(std::make_shared<Coordinates>(getX(), getY() - getSpeed()));
	if (getY() + getSpeed() < 800)
		surroundingCells.push_back(std::make_shared<Coordinates>(getX(), getY() + getSpeed()));
	if (getX() - getSpeed() > 0)
		surroundingCells.push_back(std::make_shared<Coordinates>(getX() - getSpeed(), getY()));
	if (getX() + getSpeed() < 800)
		surroundingCells.push_back(std::make_shared<Coordinates>(getX() + getSpeed(), getY()));

	return surroundingCells;
}
void Character::wanderAroundRoom()
{ // Makes the character move around the room on it's own it the player doesn't direct it for a certain amount of time
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
		/*
		else if (!checkLocation(surroundingCells[i]->getX() + getSpeed(), surroundingCells[i]->getY()))
		{
			setPreviousLocation(getX(), getY());
			setX(getX() + getSpeed());
		}
		else if (!checkLocation(surroundingCells[i]->getX(), surroundingCells[i]->getY() - getSpeed())) //need to change to pass in screen dimensions
		{
			setPreviousLocation(getX(), getY());
			setY(getY() - getSpeed());
		}
		else if (!checkLocation(surroundingCells[i]->getX() - getSpeed(), surroundingCells[i]->getY()))
		{
			setPreviousLocation(getX(), getY());
			setX(getX() - getSpeed());
		}*/
	}

	

	/*
	
	if (isCellARoom(getX(), getY() + getSpeed()) && (getY() + getSpeed()) < 800 - getSize() && !checkLocation(getX(), getY() + getSpeed()))
	{
		setPreviousLocation(getX(), getY());
		setY(getY() + getSpeed());		
	}
	else if (isCellARoom(getX() + getSpeed(), getY()) && (getX() + getSpeed()) < 800 - getSize() && !checkLocation(getX() + getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() + getSpeed());
	}
	else if (isCellARoom(getX(), getY() - getSpeed()) && (getY() + getSpeed()) > 0 + getSize() && !checkLocation(getX(), getY() - getSpeed())) //need to change to pass in screen dimensions
	{
		setPreviousLocation(getX(), getY());
		setY(getY() - getSpeed());
	}	
	else if (isCellARoom(getX() - getSpeed(), getY()))
	{
		setPreviousLocation(getX(), getY());
		setX(getX() - getSpeed());
	}*/
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