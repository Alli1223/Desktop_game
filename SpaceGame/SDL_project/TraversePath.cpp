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
	//if (previousPoint.getX() < point.getX() && previousPoint.getX() > 0 && point.getY() == previousPoint.getY())

	if (point.getX() == previousPoint.getX())
		VerticalMovement(characterOne, point);

	if (point.getY() == previousPoint.getY())
		HorizontalMovement(characterOne, point);

	//VerticalMovement(characterOne, point);
	previousPoint = point;
}
void TraversePath::VerticalMovement(Character& characterOne, Point point)
{
	int pointY = point.getY() * 25;
	//move down
	if (characterOne.getY() < pointY)
		characterOne.setY(characterOne.getY() + 1);
	//move up
	else if (characterOne.getY() > pointY)
		characterOne.setY(characterOne.getY() - 1);
	else if (characterOne.getY() == pointY)
		seekNextNode(characterOne, point);

}

void TraversePath::HorizontalMovement(Character& characterOne, Point point)
{
	int pointX = point.getX() * 25;
	//move right
	if (characterOne.getX() < pointX)
		characterOne.setX(characterOne.getX() + 1);
	//move left
	else if (characterOne.getX() > pointX)
		characterOne.setX(characterOne.getX() - 1);

	else if (characterOne.getX() == pointX)
		seekNextNode(characterOne, point);
}
void TraversePath::seekNextNode(Character& characterOne, Point point)
{
	int pointX = point.getX() * 25;
	int pointY = point.getY() * 25;
	if (characterOne.getX() == pointX && characterOne.getY() == pointY)
	{
		pathPointIterator++;
	}
}

Point TraversePath::getNextPoint(std::vector<Point> path)
{
	if (pathPointIterator < path.size())
		return path[pathPointIterator];
}