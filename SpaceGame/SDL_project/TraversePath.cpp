#include "stdafx.h"
#include "TraversePath.h"

TraversePath::TraversePath()
{
}


TraversePath::~TraversePath()
{
}

// Moves the player across the cell to the next cell
void TraversePath::LinearMovement(Character& characterOne, Point point)
{
	//seeks the next node in the path
	if (characterOne.getX() < point.getX() * 25) 
		characterOne.setX(characterOne.getX() + 1);
	else if (characterOne.getX() > point.getX() * 25)
		characterOne.setX(characterOne.getX() - 1);
	else if (characterOne.getX() == point.getX() * 25)
		pathPointIterator++;

	if (characterOne.getY() <= point.getY() * 25)
		characterOne.setY(characterOne.getY() + 1);
	else if (characterOne.getY() >= point.getY() * 25)
		characterOne.setY(characterOne.getY() - 1);
	else if (characterOne.getY() == point.getY() * 25)
		pathPointIterator++;
		
}

bool TraversePath::seekNextNode(Character& characterOne, Point& point)
{
	if (characterOne.getX() < point.getX() * 25 || characterOne.getY() < point.getY() * 25)
		return true;
	if (characterOne.getX() > point.getX() * 25 || characterOne.getY() > point.getY() * 25)
		return true;
	if (characterOne.getX() == point.getX() * 25 && characterOne.getY() == point.getY() * 25)
		return false;
}

Point TraversePath::getNextPoint(std::vector<Point> path)
{
	return path[pathPointIterator];
}